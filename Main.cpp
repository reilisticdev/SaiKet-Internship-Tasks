#include <windows.h>
#include <string>
#include <cstdio>

// 1. Global Variables
HWND hDisplay;
std::wstring currentInput = L"";
double storedValue = 0;
char operation = 0;
bool resetDisplay = false;

// 2. Button IDs
#define ID_BTN_0 100
#define ID_BTN_1 101
#define ID_BTN_2 102
#define ID_BTN_3 103
#define ID_BTN_4 104
#define ID_BTN_5 105
#define ID_BTN_6 106
#define ID_BTN_7 107
#define ID_BTN_8 108
#define ID_BTN_9 109
#define ID_BTN_ADD 110
#define ID_BTN_SUB 111
#define ID_BTN_MUL 112
#define ID_BTN_DIV 113
#define ID_BTN_EQ  114
#define ID_BTN_CLR 115

// 3. Helper Functions
void UpdateDisplay() {
    SetWindowTextW(hDisplay, currentInput.c_str());
}

// 4. Button Logic
void HandleButton(int id) {
    if (id >= ID_BTN_0 && id <= ID_BTN_9) {
        if (resetDisplay) { currentInput = L""; resetDisplay = false; }
        currentInput += std::to_wstring(id - ID_BTN_0);
        UpdateDisplay();
    }
    else if (id == ID_BTN_CLR) {
        currentInput = L""; storedValue = 0; operation = 0; UpdateDisplay();
    }
    else if (id == ID_BTN_ADD || id == ID_BTN_SUB || id == ID_BTN_MUL || id == ID_BTN_DIV) {
        if (!currentInput.empty()) {
            storedValue = std::stod(currentInput);
            currentInput = L"";
            if (id == ID_BTN_ADD) operation = '+';
            if (id == ID_BTN_SUB) operation = '-';
            if (id == ID_BTN_MUL) operation = '*';
            if (id == ID_BTN_DIV) operation = '/';
        }
    }
    else if (id == ID_BTN_EQ) {
        if (operation != 0 && !currentInput.empty()) {
            double secondVal = std::stod(currentInput);
            double result = 0;
            if (operation == '+') result = storedValue + secondVal;
            if (operation == '-') result = storedValue - secondVal;
            if (operation == '*') result = storedValue * secondVal;
            if (operation == '/') result = (secondVal == 0) ? 0 : storedValue / secondVal;

            wchar_t buffer[50];
            swprintf_s(buffer, 50, L"%.6g", result);
            currentInput = buffer;
            UpdateDisplay();
            operation = 0; resetDisplay = true;
        }
    }
}

// 5. Window Setup
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        hDisplay = CreateWindowW(L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_RIGHT | WS_BORDER,
            10, 10, 260, 40, hwnd, NULL, NULL, NULL);

        // Draw Buttons
        CreateWindowW(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, 10, 60, 60, 60, hwnd, (HMENU)ID_BTN_7, NULL, NULL);
        CreateWindowW(L"BUTTON", L"8", WS_CHILD | WS_VISIBLE, 75, 60, 60, 60, hwnd, (HMENU)ID_BTN_8, NULL, NULL);
        CreateWindowW(L"BUTTON", L"9", WS_CHILD | WS_VISIBLE, 140, 60, 60, 60, hwnd, (HMENU)ID_BTN_9, NULL, NULL);
        CreateWindowW(L"BUTTON", L"/", WS_CHILD | WS_VISIBLE, 205, 60, 60, 60, hwnd, (HMENU)ID_BTN_DIV, NULL, NULL);

        CreateWindowW(L"BUTTON", L"4", WS_CHILD | WS_VISIBLE, 10, 125, 60, 60, hwnd, (HMENU)ID_BTN_4, NULL, NULL);
        CreateWindowW(L"BUTTON", L"5", WS_CHILD | WS_VISIBLE, 75, 125, 60, 60, hwnd, (HMENU)ID_BTN_5, NULL, NULL);
        CreateWindowW(L"BUTTON", L"6", WS_CHILD | WS_VISIBLE, 140, 125, 60, 60, hwnd, (HMENU)ID_BTN_6, NULL, NULL);
        CreateWindowW(L"BUTTON", L"*", WS_CHILD | WS_VISIBLE, 205, 125, 60, 60, hwnd, (HMENU)ID_BTN_MUL, NULL, NULL);

        CreateWindowW(L"BUTTON", L"1", WS_CHILD | WS_VISIBLE, 10, 190, 60, 60, hwnd, (HMENU)ID_BTN_1, NULL, NULL);
        CreateWindowW(L"BUTTON", L"2", WS_CHILD | WS_VISIBLE, 75, 190, 60, 60, hwnd, (HMENU)ID_BTN_2, NULL, NULL);
        CreateWindowW(L"BUTTON", L"3", WS_CHILD | WS_VISIBLE, 140, 190, 60, 60, hwnd, (HMENU)ID_BTN_3, NULL, NULL);
        CreateWindowW(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, 205, 190, 60, 60, hwnd, (HMENU)ID_BTN_SUB, NULL, NULL);

        CreateWindowW(L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, 10, 255, 60, 60, hwnd, (HMENU)ID_BTN_CLR, NULL, NULL);
        CreateWindowW(L"BUTTON", L"0", WS_CHILD | WS_VISIBLE, 75, 255, 60, 60, hwnd, (HMENU)ID_BTN_0, NULL, NULL);
        CreateWindowW(L"BUTTON", L"=", WS_CHILD | WS_VISIBLE, 140, 255, 60, 60, hwnd, (HMENU)ID_BTN_EQ, NULL, NULL);
        CreateWindowW(L"BUTTON", L"+", WS_CHILD | WS_VISIBLE, 205, 255, 60, 60, hwnd, (HMENU)ID_BTN_ADD, NULL, NULL);
        break;

    case WM_COMMAND:
        HandleButton(LOWORD(wParam));
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

// 6. Main Entry Point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSW wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"CalcClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);
    HWND hwnd = CreateWindowExW(0, L"CalcClass", L"SaiKet Task 1", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 370, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    MSG msg = { };
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
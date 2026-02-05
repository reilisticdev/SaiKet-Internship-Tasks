# SaiKet Systems - C/C++ Development Internship 🚀

**Internship Period:** January 2026 - Present  
**Role:** C/C++ Software Development Intern (Remote)  
**Company:** SaiKet Systems

## 📖 About This Repository
This repository documents my work and technical submissions for the C/C++ Development Internship at SaiKet Systems. Each folder corresponds to a specific task assigned during the program, showcasing solutions built from scratch using C++ and standard industry practices.

---

## 📂 Task List

### ✅ Task 1: GUI Calculator (Native Windows API)
**Status:** Completed  
**Location:** `/Task 1`

A fully functional Graphical User Interface (GUI) calculator built entirely in **C++ using the native Win32 API**. 

Unlike standard solutions that rely on heavy external frameworks (like Qt or wxWidgets), this application interacts directly with the Windows OS. This approach demonstrates a deep understanding of memory management, event loops, and system-level programming.

**Key Features:**
* **Native Performance:** Built with pure C++ and `windows.h` for zero dependency overhead.
* **Arithmetic Engine:** Handles Addition, Subtraction, Multiplication, and Division with error handling (e.g., division by zero).
* **Modern UI:** Implements `Segoe UI` fonts via `WM_SETFONT` for a clean look, overriding the default system fonts.
* **Keyboard Support:** Users can input numbers and operations using the Numpad or keyboard keys (handling `WM_CHAR` events).
* **Input Validation:** Prevents syntax errors like multiple decimal points.

**Technical Highlights:**
* Manual handling of the Windows Message Loop (`GetMessage`, `DispatchMessage`).
* Custom `WindowProc` callback function for event processing.
* Dynamic memory & resource management (GDI Objects).

---

### 🚧 Task 2: [Coming Soon]
**Status:** In Progress  
*Description will be updated upon completion.*

---

### 🚧 Task 3: [Coming Soon]
**Status:** Pending  
*Description will be updated upon completion.*

---

### 🚧 Task 4: [Coming Soon]
**Status:** Pending  
*Description will be updated upon completion.*

---

## 🛠️ Tech Stack & Tools
* **Language:** C++ (C++20 Standard)
* **IDE:** Visual Studio 2026 (Enterprise/Community)
* **Frameworks:** Win32 API (Windows.h)
* **Version Control:** Git & GitHub

## 🚀 How to Run Task 1
1.  Clone this repository.
2.  Open **Visual Studio** and create a new **Empty Project (C++)**.
3.  Copy the code from `Task 1/Main.cpp` into your project source file.
4.  **Important Configuration:**
    * Right-click Project > Properties > **Linker** > **System**.
    * Set **SubSystem** to `Windows (/SUBSYSTEM:WINDOWS)`.
5.  Build and Run (F5).

---
*Internship work submitted by Reilyn Kevin Naidoo.*

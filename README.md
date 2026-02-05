# SaiKet Systems - C/C++ Development Internship 🚀

**Internship Period:** January 2026 - Present  
**Role:** C/C++ Software Development Intern (Remote)  
**Company:** SaiKet Systems

## 📖 About This Repository
This repository documents my work and technical submissions for the C/C++ Development Internship at SaiKet Systems. I have successfully completed the required 4 tasks, showcasing solutions built from scratch using C++ and standard industry practices.

---

## 📂 Task List

### ✅ Task 1: GUI Calculator (Native Windows API)
**Status:** Completed  
**Location:** `/Task 1`

A fully functional Graphical User Interface (GUI) calculator built entirely in **C++ using the native Win32 API**. Unlike standard solutions that rely on heavy external frameworks, this application interacts directly with the Windows OS.

**Key Features:**
* **Native Performance:** Built with pure C++ and `windows.h` for zero dependency overhead.
* **Event-Driven Architecture:** Manages the Windows Message Loop manually.
* **Modern UI:** Implements `Segoe UI` fonts via `WM_SETFONT`.
* **Input Handling:** Supports both mouse clicks and keyboard input (Numpad support).

---

### ✅ Task 2: To-Do List Application (Console)
**Status:** Completed  
**Location:** `/Task 2`

A robust console-based task management system designed to demonstrate proficiency in **C++ Data Structures** and **Memory Management**. It allows users to manage their daily tasks efficiently through a text-based interface.

**Key Features:**
* **Dynamic Storage:** Uses `std::vector` and `struct` to manage a dynamic list of tasks.
* **CRUD Operations:** Users can **Create** (Add), **Read** (View), **Update** (Mark Complete), and **Delete** (Remove) tasks.
* **Input Validation:** Robust error handling to prevent crashes when users enter invalid numbers.

---

### ✅ Task 3: Simple Text Editor (File I/O)
**Status:** Completed  
**Location:** `/Task 3`

A persistent "Mini-Notepad" that demonstrates **File Input/Output** operations. This program interacts directly with the hard drive to create, save, and read real text files.

**Key Features:**
* **File Persistence:** Uses `std::ofstream` (write) and `std::ifstream` (read) to save data permanently to the disk.
* **Continuous Input Mode:** Allows users to write multiple lines of text until a specific save command (`:SAVE`) is triggered.
* **Buffer Management:** Implements input clearing to handle the transition between menu selection and text entry smoothly.

---

### ✅ Task 4: Tic-Tac-Toe Game
**Status:** Completed  
**Location:** `/Task 4`

A classic two-player console game that demonstrates complex **Game Logic** and **State Management**.

**Key Features:**
* **Visual Grid System:** Uses `system("cls")` to redraw the board after every move, creating a clean, frame-like experience instead of a scrolling log.
* **Win/Draw Detection:** Instantaneously checks rows, columns, and diagonals for a win condition after every turn.
* **Input Protection:** Prevents users from crashing the game by entering letters or selecting occupied slots.
* **2D Array Logic:** efficient management of the 3x3 game board using multi-dimensional arrays.

---

### ✅ Task 5: Inventory System (Advanced)
**Status:** Completed  
**Location:** `/Task 5`

A professional inventory management tool that calculates stock value and formats reports using `iomanip`.

**Key Features:**
* **Formatted Reporting:** Uses `std::setw` and `std::left` to generate perfectly aligned, receipt-style tables in the console.
* **Financial Logic:** Automatically calculates total asset value (Quantity × Price) for individual items and the entire stock.
* **Smart Updates:** Allows targeted modification of specific item attributes (Price or Quantity) without needing to re-enter all data.
* **Auto-Incrementing IDs:** Simulates a real database by assigning unique tracking numbers to every new product.

### 🔹 Task 6: Address Book
**Status:** Optional (Requirement Met)

---

## 🛠️ Tech Stack & Tools
* **Language:** C++ (C++20 Standard)
* **IDE:** Visual Studio 2026
* **Frameworks:** Win32 API (Task 1), C++ Standard Library (Tasks 2-4)
* **Key Concepts:** Event Handling, File I/O, Data Structures (Vectors), Game Logic, 2D Arrays.

## 🚀 How to Run The Projects

**To Run Task 1 (GUI App):**
1. Open the project in Visual Studio.
2. Set the Linker System to **Windows** (`/SUBSYSTEM:WINDOWS`).
3. Build and Run.

**To Run Tasks 2, 3, & 4 (Console Apps):**
1. Open the project in Visual Studio.
2. Set the Linker System to **Console** (`/SUBSYSTEM:CONSOLE`).
3. Build and Run.

---
*Internship work submitted by Reilyn Kevin Naidoo.*

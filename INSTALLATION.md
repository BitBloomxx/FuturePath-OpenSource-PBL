# Installation and Usage

## Prerequisites

Before running the project, ensure you have the following installed:

- Git
- A C++17 compatible compiler (such as GCC/G++)
- Visual Studio Code (optional, for development)

---

## Clone the Repository

Clone the repository to your local machine using Git:

```bash
git clone https://github.com/BitBloomxx/FuturePath-OpenSource-PBL.git
```

Navigate to the project directory:

```bash
cd FuturePath-OpenSource-PBL
```

---

## Compile the Project

Compile the source code using a C++17 compatible compiler:

```bash
g++ -std=c++17 main.cpp -o FuturePath
```

This command generates an executable named:

- **FuturePath.exe** on Windows
- **FuturePath** on Linux/macOS

---

## Run the Program

### Windows

```bash
.\FuturePath.exe
```

### Linux/macOS

```bash
./FuturePath
```

---

## Running the Project in Visual Studio Code

If you are using Visual Studio Code:

1. Open the cloned project folder.
2. Open `main.cpp`.
3. Click **Run Code** (or use your configured run shortcut).
4. The program will compile and execute within the integrated terminal or output window.

---

## Usage

Once the application starts:

1. Follow the on-screen prompts displayed in the terminal.
2. Enter the required student details when prompted.
3. Select the appropriate department and placement company.
4. Provide academic information such as SGPA/CGPA and other requested details.
5. View the generated placement eligibility and package prediction results.
6. Repeat the process for additional students or exit the application using the available menu options.

---

## Troubleshooting

- Ensure a C++17 compatible compiler is installed on your system.
- If the `g++` command is not recognized, verify that your compiler is installed correctly and added to your system's PATH environment variable.
- Make sure you are inside the project directory before compiling.
- If compilation fails, review the compiler error messages and ensure all project files are present.

---

## Notes

This project is a console-based C++ application developed as a **Training and Placement (T&P) Cell Management System**. The program is designed to be compiled with a standard C++17 compiler and can be run either from the command line or directly through Visual Studio Code.

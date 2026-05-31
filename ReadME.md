

# student_id_ads2_project

Compilation and run instructions

Prerequisites:
- A C compiler (GCC/Clang) and `make` on Linux/macOS
- On Windows: MSYS2/MinGW (with `make`) or Visual Studio + CMake

Linux (recommended)

Build:
```bash
make
```

Run:
```bash
./output/demo
```

Clean:
```bash
make clean
```

Alternative (compile a single file):
```bash
gcc -g src/<file>.c -o bin/<executable>
```

Windows

Option A — MSYS2 / MinGW (Unix-like shell)

Install MSYS2 and the `mingw-w64` toolchain, open an MSYS2 MinGW64 shell, then:
```bash
make
.\output\demo.exe
make clean
```

Option B — Visual Studio + CMake (native build)

Open a "Developer Command Prompt for VS" and run:
```powershell
cmake -S . -B build -G "NMake Makefiles"
cmake --build build --config Release
.\build\output\demo.exe
```

Notes:
- The `Makefile` in the repository is the primary build target; prefer `make` on Linux or MSYS2.
- On Windows the executable is `output\demo.exe` (use backslashes in PowerShell/CMD).
- If you need help configuring MSYS2 or Visual Studio builds, tell me which environment you use.



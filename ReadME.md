

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

Bonus Demo (DSA Demo)
----------------------
The project includes a small dataset-analysis demo located in the `Bonus/` folder. You can build and run it in three ways:

- From the repository root (uses the new `bonus_demo` target in the top-level Makefile):
```bash
make bonus_demo
./output/dsa_demo
```

- From the `Bonus/` directory (local Makefile that links the required library sources):
```bash
cd Bonus
make
./output/DSA-Demo
```

- With CMake (build only the `dsa_demo` target):
```bash
cmake -S . -B build
cmake --build build --target dsa_demo
./build/output/dsa_demo
```

Notes:
- The `Makefile` at [Makefile](Makefile) exposes `bonus_demo`.
- There's also a local [Bonus/Makefile](Bonus/Makefile) so you can build from inside the `Bonus/` folder.
- The CMake target `dsa_demo` is added via [CMakeLists.txt](CMakeLists.txt) and writes its executable to the build `output/` directory.

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



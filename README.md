# 📚 string.h & math.h C Library Clone

> A from-scratch implementation of C's standard `string.h` and `math.h` libraries, built to demonstrate the concepts of **Static Linking** and **Dynamic Linking** in C.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Implemented Functions](#implemented-functions)
  - [string.h Functions](#stringh-functions)
  - [math.h Functions](#mathh-functions)
- [Linking in C — Concepts Explained](#linking-in-c--concepts-explained)
  - [Static Linking](#static-linking)
  - [Dynamic Linking](#dynamic-linking)
  - [Comparison Table](#comparison-table)
- [How to Build](#how-to-build)
  - [Build as Static Library](#build-as-static-library)
  - [Build as Dynamic Library](#build-as-dynamic-library)
- [How to Use](#how-to-use)
  - [Linking Statically](#linking-statically)
  - [Linking Dynamically](#linking-dynamically)
- [Requirements](#requirements)
- [Learning Objectives](#learning-objectives)
- [Author](#author)

---

## Overview

This project is a **custom re-implementation** of two of the most commonly used C standard libraries:

- **`string.h`** — Functions for string manipulation and memory operations
- **`math.h`** — Functions for mathematical computations

The primary goal is **not** to replace the standard library, but to understand:
1. How standard library functions work under the hood
2. How C libraries are compiled and packaged
3. The difference between **static** (`.a`) and **dynamic/shared** (`.so` / `.dll`) linking

---

## Implemented Functions

### string.h Functions

> Custom type `BOOL` is defined as `int` with macros `TRUE (1)` and `FALSE (0)`.

| Function | Signature | Description |
|---|---|---|
| `Mystrlen` | `int Mystrlen(char *str)` | Returns the length of a string |
| `MyStrCpy` | `void MyStrCpy(char *str, char *dest)` | Copies string from str into dest |
| `MyStrncpy` | `void MyStrncpy(char *str, char *dest, int ino)` | Copies at most `ino` characters from str into dest |
| `MyStrcat` | `void MyStrcat(char *str1, char *str2, char *dest)` | Concatenates str1 and str2 into dest |
| `MyStrCmp` | `BOOL MyStrCmp(char *str1, char *str2)` | Compares two strings; returns TRUE if equal |
| `MyStrnCmp` | `BOOL MyStrnCmp(char *str1, char *str2, int iNo)` | Compares first `iNo` characters of two strings |
| `MyStrRev` | `void MyStrRev(char *str, char *revString)` | Reverses str and stores result in revString |
| `MyStrchr` | `int MyStrchr(char *str, char ch)` | Returns index of first occurrence of ch in str, -1 if not found |
| `MyStrStr` | `int MyStrStr(char *str1, char *str2)` | Returns starting index of str2 in str1, -1 if not found |

---

### math.h Functions

| Function | Signature | Description |
|---|---|---|
| `MyPow` | `int MyPow(int iNo, int iNo2)` | Returns iNo raised to the power iNo2 |
| `MySqrt` | `int MySqrt(int iNo)` | Returns integer square root of iNo |
| `MyAbs` | `int MyAbs(int iNo)` | Returns absolute value of iNo |
| `MyMax` | `int MyMax(int iNo, int iNo2)` | Returns the larger of two integers |
| `MyMin` | `int MyMin(int iNo, int iNo2)` | Returns the smaller of two integers |
| `MyFactorial` | `int MyFactorial(int iNo)` | Returns factorial of iNo |
| `MyGCD` | `int MyGCD(int iNo, int iNo2)` | Returns Greatest Common Divisor of two integers |
| `MyLCM` | `int MyLCM(int iNo, int iNo2)` | Returns Least Common Multiple of two integers |

---

## Linking in C — Concepts Explained

### Static Linking

In **static linking**, the library code is **copied directly into the final executable** at compile time.

```
[your_program.o] + [libmylib.a]  →  [executable]
                                      (contains all library code inside)
```

**Characteristics:**
- The resulting binary is **self-contained** — no external dependencies at runtime
- Produces a **larger executable**
- Any update to the library requires **recompiling** the program
- Faster at runtime (no lookup overhead)

**File extension:** `.a` (archive) on Linux/macOS, `.lib` on Windows

---

### Dynamic Linking

In **dynamic linking**, the library is kept as a **separate file** and linked at runtime by the OS loader.

```
[your_program.o] + reference to [libmylib.so]  →  [executable]
                                                    (loads .so at runtime)
```

**Characteristics:**
- The binary is **smaller** — it only stores references to the library
- Multiple programs can **share the same library** in memory
- Library can be **updated independently** without recompiling the program
- Slightly slower startup (dynamic linker resolves symbols at load time)

**File extension:** `.so` (shared object) on Linux, `.dylib` on macOS, `.dll` on Windows

---

### Comparison Table

| Feature | Static Linking | Dynamic Linking |
|---|---|---|
| Library embedded in binary | ✅ Yes | ❌ No |
| Binary size | Larger | Smaller |
| Runtime dependency | None | Requires `.so`/`.dll` |
| Update library without recompile | ❌ No | ✅ Yes |
| Memory sharing across processes | ❌ No | ✅ Yes |
| Portability | High | Depends on runtime |
| Build time | Slightly longer | Faster |

---

## How to Build

---

### Build as Static Library

```bash
# Step 1: Compile source files into object files
gcc -c src/my_string.c -I include/ -o my_string.o
gcc -c src/my_math.c   -I include/ -o my_math.o

# Step 2: Archive into a static library
ar rcs static/libmylib.a my_string.o my_math.o

# Verify contents
ar -t static/libmylib.a
```

---

### Build as Dynamic Library

```bash
# Step 1: Compile with Position-Independent Code (PIC)
gcc -c -fPIC src/my_string.c -I include/ -o my_string.o
gcc -c -fPIC src/my_math.c   -I include/ -o my_math.o

# Step 2: Create shared library
gcc -shared -o dynamic/libmylib.so my_string.o my_math.o
```

> **`-fPIC`** (Position Independent Code) is required for shared libraries so that the code can be loaded at any memory address.

---

## How to Use

### Linking Statically

```bash
gcc examples/test_string.c -I include/ -L static/ -lmylib -o test_static
./test_static
```

The `-lmylib` flag tells the linker to look for `libmylib.a` in the path specified by `-L`.

---

### Linking Dynamically

```bash
gcc examples/test_string.c -I include/ -L dynamic/ -lmylib -o test_dynamic

# Tell the OS where to find the .so at runtime
export LD_LIBRARY_PATH=./dynamic:$LD_LIBRARY_PATH

./test_dynamic
```

---

## Requirements

- GCC (GNU Compiler Collection) `>= 7.0`
- GNU Make `>= 4.0`
- Linux / macOS (Windows support via WSL or MinGW)

---

## Learning Objectives

By exploring this project, you will learn:

- ✅ How to write and organize a C library from scratch
- ✅ How to compile object files and archive them into a `.a` static library
- ✅ How to compile a `.so` shared/dynamic library using `-fPIC` and `-shared`
- ✅ The difference between static and dynamic linking and their trade-offs
- ✅ How to use `ar`, `gcc`, `ldd`, and `nm` tools for inspecting libraries
- ✅ How the OS linker resolves symbols at compile time vs runtime
- ✅ How standard C library functions work internally

---

> ⭐ If this project helped you understand linking in C, consider giving it a star!

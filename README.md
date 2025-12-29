# Encrypter

**Encrypter** is a C-based encryption program demonstrating a **custom XOR encryption** combined with a **polynomial rolling hash**. This project is intended for **educational purposes**, showcasing low-level file handling, hashing, and multi-file C project structure.

---

## ⚠️ Disclaimer
This program is **educational only**.  
It uses a custom encryption scheme and is **not secure for real-world use**. Do **not** use it to protect sensitive data.

---

## Features
- Encrypts text using XOR logic  
- Uses polynomial rolling hashing for data transformation  
- Written in pure C  
- Demonstrates file I/O and multi-file project organization  

---

## Project Structure
Encrypter/

├── Source.c # Main program logic

├── util.c # Helper function implementations

├── util.h # Function declarations

├── README.md # Project documentation

├── LICENSE # MIT License

├── encrypter.exe # Compiled executable (Windows)

## For End Users (Windows)
If you just want to run the program:
1. Download `encrypter.exe`  
2. Run it from the command line:
```bash
encrypter.exe
```
For Developers (Build from Source)
To compile the program yourself, use GCC (MinGW on Windows, Linux, or macOS):
## Linux / macOS
```bash
gcc Source.c util.c -o encrypter
```
## Windows
```bash
gcc Source.c util.c -o encrypter.exe
```
Then run:
## Linux / macOS
```bash
./encrypter
```
## Windows
```bash
encrypter.exe
```
# Goals
Practice C programming

Learn basic encryption and hashing

Understand multi-file project organization

Gain experience with compilation and linking

License
This project is licensed under the MIT License.
See the LICENSE file for details.

# SHA-512 Cryptographic Hash Implementation in C++

### Final Year BTech Project  
**By:** Sannidhy Prabhakar, Sarish Vikrant Nilakhe, Navin Kumar  
**Institution:** [Your University Name Here]

---

## Overview

This C++ project implements the **SHA-512 hashing algorithm**—a cornerstone of modern cryptography and data integrity. Designed and implemented as part of the Final Year BTech Project, this program transforms a human-readable input string into a fixed 512-bit (64-byte) cryptographic hash.

From binary paddings to bitwise magic, and modular arithmetic to sigma transformations, this implementation captures the full beauty of SHA-512's inner machinery.

---

## Features

- Full SHA-512 hash function implementation from scratch (no external libraries).
- Binary operations implemented manually (`XOR`, `AND`, `NOT`, `SHR`, `ROTR`).
- Message pre-processing with padding and 1024-bit chunk splitting.
- Word expansion to 80 64-bit words per block.
- Message compression using SHA-512 round functions (`Ch`, `Maj`, `Σ0`, `Σ1`, `σ0`, `σ1`).
- Uses a predefined list of 80 SHA-512 constants (`K` values).
- Final digest computed using 64-bit additions modulo `2^64`.

---

## Structure

- **Input:** A text string from `cin`.
- **Output:** Binary SHA-512 hash printed to stdout.
- **Main Steps:**
  1. Convert text to binary (`TextToBinaryString`)
  2. Calculate padding (`num_padding`)
  3. Append padding and original length (`padding`)
  4. Break into 1024-bit chunks
  5. Create 80-word schedule
  6. Process each block using SHA-512 compression loop
  7. Output final hash state

---

## Build Instructions

### Requirements
- C++17 or later
- Standard g++ or clang compiler

### Compilation
```bash
g++ sha512.cpp -o sha512

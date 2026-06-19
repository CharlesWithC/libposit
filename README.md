# libposit

An assembly wrapper library for 16-bit and 32-bit POSIT instructions based on Xposit.

This library provides a base C library with wrapper functions, and a C++ library with operator overloading.

In addition, this library utilizes [SoftPosit](https://github.com/HPCC-UNUM/SoftPosit) for software-based conversion between posit and double. Note that posit16 was adapted to use `es=2` instead of `es=1` from the original repo.

A modified version of [llvm-xposit](https://github.com/CharlesWithC/llvm-xposit) is used for full posit register support in LLVM. This allows LLVM to allocate registers automatically and efficiently.

Detailed documentation to use this library will be added in the near future in the form of a LaTeX-based report.

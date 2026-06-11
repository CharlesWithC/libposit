# libposit

An assembly wrapper library for POSIT instructions based on Xposit.

This library provides a base C library with wrapper functions, and a C++ library with operator overloading.

This library is based on an updated version of [llvm-xposit](https://github.com/CharlesWithC/llvm-xposit/tree/register-fix), where I implemented full posit register support in LLVM, which allows LLVM to allocate registers efficiently.

Note that while updating `llvm-xposit` and implementing `libposit`, I discovered a potential hardware hazard that causes issues in certain cases when the result from `pmv.x.w` is used. I decided to not introduce any "hack" at `llvm-xposit` level to avoid performance impact or future rework, and so the workaround should added at library and application level. The detailed issue and workaround are documented in [posit.h](/include/posit.h). It is recommended to use the C++ library when possible, as it introduces a safeguard on the direct use of Posit value where `pmvxw` is called automatically when the value is to be used naively.

Detailed documentation to use this library will be added in the near future in the form of a LaTeX-based report.

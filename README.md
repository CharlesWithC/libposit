# libposit

An assembly wrapper library for 16-bit and 32-bit POSIT instructions based on Xposit.

This library provides a base C library with wrapper functions, and a C++ library with operator overloading.

This library is based on an updated version of [llvm-xposit](https://github.com/CharlesWithC/llvm-xposit/tree/register-fix), where I implemented full posit register support in LLVM, which allows LLVM to allocate registers efficiently.

Detailed documentation to use this library will be added in the near future in the form of a LaTeX-based report.

## Potential Hardware Hazard

While testing the library, I discovered a weird issue with posit value loading, storing and copying to/from GPR. I cannot determine the cause, but the inconsistency of the issue and the seemingly-correct disassembly make me lean towards a potential hardware issue. I attach an objective summary of the issue below:

1. In posit32, it is possible to use full `pmv.x.w` and `pmv.w.x` to copy PosReg to/from GPR and get correct results, except that the user must explicitly call `pmv.x.w` when using a posit value in a GPR-based operation (such as comparing with integer). The user must not rely on LLVM's automatic COPY because the value that should be copied to GPR does not always seem immediately available, and the GPR seems to be overwritten asynchronously in certain cases.

2. In posit16, the only viable approach to correctly bitcast posit values is to use a combination of `psw` for storing posit values to memory and `pmvwx` for loading posit values from integer. The data is corrupted in certain cases when using `plw` to load posit values and `pmvxw` to copy posit values to register. Detailed behavior is not tested due to this case being more unexpected, but a possible explanation is that 16-bit values require some extra special handling that wasn't discovered and added to this library.

These potential hazards are addressed in the C++ library, but C-library users must handle them explicitly to prevent data corruption.

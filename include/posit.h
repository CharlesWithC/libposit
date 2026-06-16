// posit.h

#ifndef POSIT_H
#define POSIT_H

#include <stdint.h>
#include <stdbool.h>

// use uint32_t for both posit16 and posit32 because GPR is 32bit
// uint16_t may cause unexpected behaviors
// this should be improved in the future along with llvm-xposit
//
// note: this library targets hardware that supports EITHER posit16 OR posit32
// i.e. the hardware is synthesized for only one of them, and same instruction
// is used for both posit sizes. thus this library does not care posit size.
typedef uint32_t posit_t;

static inline posit_t padd(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "padd.s %0,%1,%2   \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t psub(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "psub.s %0,%1,%2   \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t pmul(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "pmul.s %0,%1,%2   \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t pdiv(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "pdiv.s %0,%1,%2   \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t psqrt(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "psqrt.s %0,%1     \n"

        : "=p" (result)
        : "p" (x)
        :
    );

    return result;
}

static inline posit_t pmin(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "pmin.s  %0,%1,%2  \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t pmax(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "pmax.s  %0,%1,%2  \n"

        : "=p" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline bool peq(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "peq.s  %0,%1,%2   \n"

        : "=r" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline bool plt(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "plt.s  %0,%1,%2   \n"

        : "=r" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline bool ple(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "ple.s  %0,%1,%2   \n"

        : "=r" (result)
        : "p" (x), "p" (y)
        :
    );

    return result;
}

static inline posit_t plw(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "plw     %0,%1     \n"

        : "=p" (result)
        : "m" (x)
        :
    );

    return result;
}

static inline posit_t psw(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "psw     %1,%0     \n"

        : "=m" (result)
        : "p" (x)
        :
    );

    return result;
}

static inline posit_t pmvxw(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "pmv.x.w %0,%1     \n"

        : "=r" (result)
        : "p" (x)
        :
    );

    return result;
}

static inline posit_t pmvwx(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "pmv.w.x %0,%1     \n"

        : "=p" (result)
        : "r" (x)
        :
    );

    return result;
}

#endif

// posit.h

#ifndef POSIT_H
#define POSIT_H

#include <stdint.h>
#include <stdbool.h>

// allow custom config for posit bits
// default: 32 bits
#ifndef POSIT_BITS
#define POSIT_BITS 32
#endif

#if POSIT_BITS == 16
#define UINT_TYPE uint16_t
#define INT_TYPE int16_t
#else
#if POSIT_BITS == 32
#define UINT_TYPE uint32_t
#define INT_TYPE int32_t
#else
#error "Invalid POSIT_BITS"
#endif
#endif

typedef UINT_TYPE posit_t;

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

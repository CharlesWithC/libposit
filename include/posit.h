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

#if POSIT_BITS == 8
#define UINT_TYPE uint8_t
#define INT_TYPE int8_t
#else
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
#endif

typedef INT_TYPE posit_t;

static inline posit_t padd(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "padd.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline posit_t psub(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "psub.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline posit_t pmul(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "pmul.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline posit_t pdiv(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "pdiv.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline posit_t psqrt(posit_t x) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "psqrt.s pt1,pt0    \n"
        "psw    pt1,%0      \n"

        : "=m" (result)
        : "m" (x), "rm" (result)
        :
    );

    return result;
}

static inline posit_t pmin(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "pmin.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline posit_t pmax(posit_t x, posit_t y) {
    posit_t result = 0;

    asm inline volatile (
        "plw    pt0,%1      \n"
        "plw    pt1,%2      \n"
        "pmax.s pt2,pt0,pt1 \n"
        "psw    pt2,%0      \n"

        : "=m" (result)
        : "m" (x), "m" (y), "rm" (result)
        :
    );

    return result;
}

static inline INT_TYPE pcvtws(posit_t x) {
    INT_TYPE result = 0;

    asm inline volatile (
        "plw    pt0,%1     \n"
        "pcvt.w.s %0,pt0   \n"

        : "=r" (result)
        : "m" (x)
        :
    );

    return result;
}

static inline UINT_TYPE pcvtwus(posit_t x) {
    UINT_TYPE result = 0;

    asm inline volatile (
        "plw    pt0,%1     \n"
        "pcvt.wu.s %0,pt0  \n"

        : "=r" (result)
        : "m" (x)
        :
    );

    return result;
}

static inline posit_t pcvtsw(INT_TYPE x) {
    posit_t result = 0;

    asm inline volatile (
        "pcvt.s.w pt0,%1   \n"
        "psw    pt0,%0     \n"

        : "=m" (result)
        : "r" (x), "rm" (result)
        :
    );

    return result;
}

static inline posit_t pcvtswu(UINT_TYPE x) {
    posit_t result = 0;

    asm inline volatile (
        "pcvt.s.wu pt0,%1  \n"
        "psw    pt0,%0     \n"

        : "=m" (result)
        : "r" (x), "rm" (result)
        :
    );

    return result;
}

static inline bool peq(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "plw    pt0,%1     \n"
        "plw    pt1,%2     \n"
        "peq.s  %0,pt0,pt1 \n"

        : "=r" (result)
        : "m" (x), "m" (y)
        :
    );

    return result;
}

static inline bool plt(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "plw    pt0,%1     \n"
        "plw    pt1,%2     \n"
        "plt.s  %0,pt0,pt1 \n"

        : "=r" (result)
        : "m" (x), "m" (y)
        :
    );

    return result;
}

static inline bool ple(posit_t x, posit_t y) {
    bool result = 0;

    asm inline volatile (
        "plw    pt0,%1     \n"
        "plw    pt1,%2     \n"
        "ple.s  %0,pt0,pt1 \n"

        : "=r" (result)
        : "m" (x), "m" (y)
        :
    );

    return result;
}

#endif

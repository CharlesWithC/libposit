#include <stdio.h>

#include "test_base.h"

#include "posit.h"

int p16add_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = padd(a, b);
    e = padd(b, a);
    f = padd(c, b);
    g = padd(a, c);

    if (psw(d) == 0x7F9AU && psw(e) == 0x7F9AU
            && psw(f) == 0x8078U && psw(g) == 0x7F40U) {
        printf("PADD test OK\n");
        return 0;
    } else {
        printf("PADD test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p16sub_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = psub(a, b);
    e = psub(b, a);
    f = psub(c, b);
    g = psub(a, c);

    if (psw(d) == 0x7F8CU && psw(e) == 0x8074U
            && psw(f) == 0x8068U && psw(g) == 0x7FA3U) {
        printf("PSUB test OK\n");
        return 0;
    } else {
        printf("PSUB test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p16mul_test() {
    posit_t a, b, c, d, e, f, g;
    posit_t cc;

    a = 0x6F12U;  // Posit  226.25
    b = 0x7B9BU;  // Posit  52608
    c = 0x87E9U;  // Posit -4464
    d = pmul(a, b);
    e = pmul(b, a);
    f = pmul(c, b);
    g = pmul(a, c);

    if (psw(d) == 0x7EDBU && psw(e) == 0x7EDBU
            && psw(f) == 0x8088U && psw(g) == 0x8209U) {
        printf("PMUL test OK\n");
        return 0;
    } else {
        printf("PMUL test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p16div_test() {
    posit_t a, b, c, d, e, f, g, h, zero;

    zero = 0;

    a = 0x6F11U;  // Posit  226.125
    b = 0x7B9BU;  // Posit  52608
    c = 0x87E9U;  // Posit -4464
    d = pdiv(a, b);
    e = pdiv(b, a);
    f = pdiv(c, b);
    g = pdiv(a, c);
    h = pdiv(a, zero);

    if (psw(d) == 0x1067U && psw(e) == 0x6F45U
            && psw(f) == 0xDD24U && psw(g) == 0xE184U
            && psw(h) == 0x8000U) {
        printf("PDIV test OK\n");
        return 0;
    } else {
        printf("PDIV test FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g, h);
        return 1;
    }
}

int p16sqrt_test() {
    posit_t a, b, c, d, e, f;

    a = 0x6F11U;  // Posit  226.125
    b = 0x7B9BU;  // Posit  52608
    c = 0x87E9U;  // Posit -4464
    d = psqrt(a);
    e = psqrt(b);
    f = psqrt(c);

    if (psw(d) == 0x5F0AU && psw(e) == 0x6F2BU
            && psw(f) == 0x8000U) {
        printf("PSQRT test OK\n");
        return 0;
    } else {
        printf("PSQRT test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int p16min_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776`
    d = pmin(a, b);
    e = pmin(b, a);
    f = pmin(c, a);
    g = pmin(c, c);

    if (psw(d) == 0x7F6FU && psw(e) == 0x7F6FU
            && psw(f) == 0x806EU && psw(g) == 0x806EU) {
        printf("PMIN test OK\n");
        return 0;
    } else {
        printf("PMIN test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p16max_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = pmax(a, b);
    e = pmax(b, a);
    f = pmax(c, a);
    g = pmax(c, c);

    if (psw(d) == 0x7F94U && psw(e) == 0x7F94U
            && psw(f) == 0x7F94U && psw(g) == 0x806EU) {
        printf("PMAX test OK\n");
        return 0;
    } else {
        printf("PMAX test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p16eq_test() {
    posit_t a, b, c;
    bool d, e, f;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = peq(a, b);
    e = peq(b, b);
    f = peq(c, c);

    if (d == 0 && e == 1 && f == 1) {
        printf("PEQ test OK\n");
        return 0;
    } else {
        printf("PEQ test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int p16lt_test() {
    posit_t a, b, c;
    bool d, e, f, g, h;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = plt(a, b);
    e = plt(b, a);
    f = plt(c, a);
    g = plt(a, c);
    h = plt(c, c);

    if (d == 0 && e == 1 && f == 1 && g == 0 && h == 0) {
        printf("PLT test OK\n");
        return 0;
    } else {
        printf("PLT test FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g, h);
        return 1;
    }
}

int p16le_test() {
    posit_t a, b, c;
    bool d, e, f, g;

    a = 0x7F94U;  // Posit  671088640
    b = 0x7F6FU;  // Posit  197132288
    c = 0x806EU;  // Posit -603979776
    d = ple(a, b);
    e = ple(b, a);
    f = ple(c, a);
    g = ple(c, c);

    if (d == 0 && e == 1 && f == 1 && g == 1) {
        printf("PLE test OK\n");
        return 0;
    } else {
        printf("PLE test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

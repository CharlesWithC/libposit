#include <stdio.h>

#include "test_base.h"

#include "posit.h"

int p16add_test() {
    posit_t a, b, c, d, e, f, g;

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
    d = psw(padd(a, b));
    e = psw(padd(b, a));
    f = psw(padd(c, b));
    g = psw(padd(a, c));

    if (d == 0x7F9A && e == 0x7F9A
            && f == 0x8078 && g == 0x7F40) {
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
    d = psw(psub(a, b));
    e = psw(psub(b, a));
    f = psw(psub(c, b));
    g = psw(psub(a, c));

    if (d == 0x7F8C && e == 0x8074
            && f == 0x8068 && g == 0x7FA3) {
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

    a = pmvwx(0x6F12);  // Posit  226.25
    b = pmvwx(0x7B9B);  // Posit  52608
    c = pmvwx(0x87E9);  // Posit -4464
    d = psw(pmul(a, b));
    e = psw(pmul(b, a));
    f = psw(pmul(c, b));
    g = psw(pmul(a, c));

    if (d == 0x7EDB && e == 0x7EDB
            && f == 0x8088 && g == 0x8209) {
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

    zero = pmvwx(0);

    a = pmvwx(0x6F11);  // Posit  226.125
    b = pmvwx(0x7B9B);  // Posit  52608
    c = pmvwx(0x87E9);  // Posit -4464
    d = psw(pdiv(a, b));
    e = psw(pdiv(b, a));
    f = psw(pdiv(c, b));
    g = psw(pdiv(a, c));
    h = psw(pdiv(a, zero));

    if (d == 0x1067 && e == 0x6F45
            && f == 0xDD24 && g == 0xE184
            && h == 0x8000) {
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

    a = pmvwx(0x6F11);  // Posit  226.125
    b = pmvwx(0x7B9B);  // Posit  52608
    c = pmvwx(0x87E9);  // Posit -4464
    d = psw(psqrt(a));
    e = psw(psqrt(b));
    f = psw(psqrt(c));

    if (d == 0x5F0A && e == 0x6F2B
            && f == 0x8000) {
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776`
    d = psw(pmin(a, b));
    e = psw(pmin(b, a));
    f = psw(pmin(c, a));
    g = psw(pmin(c, c));

    if (d == 0x7F6F && e == 0x7F6F
            && f == 0x806E && g == 0x806E) {
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
    d = psw(pmax(a, b));
    e = psw(pmax(b, a));
    f = psw(pmax(c, a));
    g = psw(pmax(c, c));

    if (d == 0x7F94 && e == 0x7F94
            && f == 0x7F94 && g == 0x806E) {
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
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

    a = pmvwx(0x7F94);  // Posit  671088640
    b = pmvwx(0x7F6F);  // Posit  197132288
    c = pmvwx(0x806E);  // Posit -603979776
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

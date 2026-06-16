#include <stdio.h>

#include "test_base.h"

#include "posit.h"

int p32add_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = padd(a, b);
    e = padd(b, a);
    f = padd(c, b);
    g = padd(a, c);

    if (pmvxw(d) == 0x7F99756F && pmvxw(e) == 0x7F99756F
            && pmvxw(f) == 0x807889A6 && pmvxw(g) == 0x7F409920) {
        printf("PADD test OK\n");
        return 0;
    }
    else {
        printf("PADD test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p32sub_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = psub(a, b);
    e = psub(b, a);
    f = psub(c, b);
    g = psub(a, c);

    if (pmvxw(d) == 0x7F8B897E && pmvxw(e) == 0x80747682
        && pmvxw(f) == 0x80689423 && pmvxw(g) == 0x7FA2984E) {
        printf("PSUB test OK\n");
        return 0;
    }
    else {
        printf("PSUB test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p32mul_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x6F10A532; // Posit  226.08066177368164
    b = 0x7B9B7665; // Posit  52667.197265625
    c = 0x87E89FBC; // Posit -4470.0166015625
    d = pmul(a, b);
    e = pmul(b, a);
    f = pmul(c, b);
    g = pmul(a, c);

    if (pmvxw(d) == 0x7EDAD7ED && pmvxw(e) == 0x7EDAD7ED
        && pmvxw(f) == 0x8087DEE8 && pmvxw(g) == 0x8209467B) {
        printf("PMUL test OK\n");
        return 0;
    }
    else {
        printf("PMUL test FAIL - Values: %x %x %x %x %x %x %x\n",
           a, b, c, d, e, f, g);
        return 1;
    }
}

int p32div_test() {
    posit_t a, b, c, d, e, f, g, h, zero;

    zero = 0;

    a = 0x6F10A532; // Posit  226.08066177368164
    b = 0x7B9B7665; // Posit  52667.197265625
    c = 0x87E89FBC; // Posit -4470.0166015625
    d = pdiv(a, b);
    e = pdiv(b, a);
    f = pdiv(c, b);
    g = pdiv(a, c);
    h = pdiv(a, zero);

    if (pmvxw(d) == 0x1065495c && pmvxw(e) == 0x6f47a910
        && pmvxw(f) == 0xdd22e2b3 && pmvxw(g) == 0xe186b030
        && pmvxw(h) == 0x80000000) {
        printf("PDIV test OK\n");
        return 0;
    }
    else {
        printf("PDIV test FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g, h);
        return 1;
    }
}

int p32sqrt_test() {
    posit_t a, b, c, d, e, f;

    a = 0x6F10A532; // Posit  226.08066177368164
    b = 0x7B9B7665; // Posit  52667.197265625
    c = 0x87E89FBC; // Posit -4470.0166015625
    d = psqrt(a);
    e = psqrt(b);
    f = psqrt(c);

    if (pmvxw(d) == 0x5F0935EA && pmvxw(e) == 0x6F2BF261
        && pmvxw(f) == 0x80000000) {
        printf("PSQRT test OK\n");
        return 0;
    }
    else {
        printf("PSQRT test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int p32min_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = pmin(a, b);
    e = pmin(b, a);
    f = pmin(c, a);
    g = pmin(c, c);

    if (pmvxw(d) == 0x7F6EC2BF && pmvxw(e) == 0x7F6EC2BF
        && pmvxw(f) == 0x806E6C7B && pmvxw(g) == 0x806E6C7B) {
        printf("PMIN test OK\n");
        return 0;
    }
    else {
        printf("PMIN test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int p32max_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = pmax(a, b);
    e = pmax(b, a);
    f = pmax(c, a);
    g = pmax(c, c);

    if (pmvxw(d) == 0x7F939D17 && pmvxw(e) == 0x7F939D17
        && pmvxw(f) == 0x7F939D17 && pmvxw(g) == 0x806E6C7B) {
        printf("PMAX test OK\n");
        return 0;
    }
    else {
        printf("PMAX test FAIL - Values: %x %x %x %x %x %x %x\n",
               a, b, c, d, e, f, g);
        return 1;
    }
}

int p32eq_test() {
    posit_t a, b, c;
    bool d, e, f;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = peq(a, b);
    e = peq(b, b);
    f = peq(c, c);

    if (d == 0 && e == 1 && f == 1) {
        printf("PEQ test OK\n");
        return 0;
    }
    else {
        printf("PEQ test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int p32lt_test() {
    posit_t a, b, c;
    bool d, e, f, g, h;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = plt(a, b);
    e = plt(b, a);
    f = plt(c, a);
    g = plt(a, c);
    h = plt(c, c);

    if (d == 0 && e == 1 && f == 1 && g == 0 && h == 0) {
        printf("PLT test OK\n");
        return 0;
    }
    else {
        printf("PLT test FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g, h);
        return 1;
    }
}

int p32le_test() {
    posit_t a, b, c;
    bool d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = ple(a, b);
    e = ple(b, a);
    f = ple(c, a);
    g = ple(c, c);

    if (d == 0 && e == 1 && f == 1 && g == 1) {
        printf("PLE test OK\n");
        return 0;
    }
    else {
        printf("PLE test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

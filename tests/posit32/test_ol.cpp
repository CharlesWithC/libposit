#include <stdio.h>

#include "test_ol.hpp"

#include "posit.hpp"

int p32add_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a + b;
    e = b + a;
    f = c + b;
    g = a + c;

    if (d.value() == 0x7F99756F && e.value() == 0x7F99756F
            && f.value() == 0x807889A6 && g.value() == 0x7F409920) {
        printf("PADD test_ol OK\n");
        return 0;
    }
    else {
        printf("PADD test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32sub_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a - b;
    e = b - a;
    f = c - b;
    g = a - c;

    if (d.value() == 0x7F8B897E && e.value() == 0x80747682
        && f.value() == 0x80689423 && g.value() == 0x7FA2984E) {
        printf("PSUB test_ol OK\n");
        return 0;
    }
    else {
        printf("PSUB test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32mul_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x6F10A532); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBC); // Posit -4470.0166015625
    d = a * b;
    e = b * a;
    f = c * b;
    g = a * c;

    if (d.value() == 0x7EDAD7ED && e.value() == 0x7EDAD7ED
        && f.value() == 0x8087DEE8 && g.value() == 0x8209467B) {
        printf("PMUL test_ol OK\n");
        return 0;
    }
    else {
        printf("PMUL test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32div_test_ol() {
    Posit a, b, c, d, e, f, g, h, zero;

    zero = Posit::from_bits(0); // convert from int 0

    a = Posit::from_bits(0x6F10A532); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBC); // Posit -4470.0166015625
    d = a / b;
    e = b / a;
    f = c / b;
    g = a / c;
    h = a / zero;

    if (d.value() == 0x1065495c && e.value() == 0x6f47a910
        && f.value() == 0xdd22e2b3 && g.value() == 0xe186b030
        && h.value() == 0x80000000) {
        printf("PDIV test_ol OK\n");
        return 0;
    }
    else {
        printf("PDIV test_ol FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value(), h.value());
        return 1;
    }
}

int p32sqrt_test_ol() {
    Posit a, b, c, d, e, f;

    a = Posit::from_bits(0x6F10A532); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBC); // Posit -4470.0166015625
    d = Posit::sqrt(a);
    e = Posit::sqrt(b);
    f = Posit::sqrt(c);

    if (d.value() == 0x5F0935EA && e.value() == 0x6F2BF261
        && f.value() == 0x80000000) {
        printf("PSQRT test OK\n");
        return 0;
    }
    else {
        printf("PSQRT test FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value());
        return 1;
    }
}

int p32min_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = Posit::min(a, b);
    e = Posit::min(b, a);
    f = Posit::min(c, a);
    g = Posit::min(c, c);

    if (d.value() == 0x7F6EC2BF && e.value() == 0x7F6EC2BF
        && f.value() == 0x806E6C7B && g.value() == 0x806E6C7B) {
        printf("PMIN test OK\n");
        return 0;
    }
    else {
        printf("PMIN test FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32max_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = Posit::max(a, b);
    e = Posit::max(b, a);
    f = Posit::max(c, a);
    g = Posit::max(c, c);

    if (d.value() == 0x7F939D17 && e.value() == 0x7F939D17
        && f.value() == 0x7F939D17 && g.value() == 0x806E6C7B) {
        printf("PMAX test OK\n");
        return 0;
    }
    else {
        printf("PMAX test FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32eq_test_ol() {
    Posit a, b, c;
    bool d, e, f;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a == b;
    e = b == b;
    f = c == c;

    if (d == 0 && e == 1 && f == 1) {
        printf("PEQ test_ol OK\n");
        return 0;
    }
    else {
        printf("PEQ test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d, e, f);
        return 1;
    }
}

int p32lt_test_ol() {
    Posit a, b, c;
    bool d, e, f, g, h;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a < b;
    e = b < a;
    f = c < a;
    g = a < c;
    h = c < c;

    if (d == 0 && e == 1 && f == 1 && g == 0 && h == 0) {
        printf("PLT test_ol OK\n");
        return 0;
    }
    else {
        printf("PLT test_ol FAIL - Values: %x %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d, e, f, g, h);
        return 1;
    }
}

int p32le_test_ol() {
    Posit a, b, c;
    bool d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a <= b;
    e = b <= a;
    f = c <= a;
    g = c <= c;

    if (d == 0 && e == 1 && f == 1 && g == 1) {
        printf("PLE test_ol OK\n");
        return 0;
    }
    else {
        printf("PLE test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d, e, f, g);
        return 1;
    }
}

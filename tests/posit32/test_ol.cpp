#include <stdio.h>

#include "test_ol.hpp"

#include "posit.hpp"

int p32add_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
    d = a + b;
    e = b + a;
    f = c + b;
    g = a + c;

    if (d.value() == 0x7F99756FU && e.value() == 0x7F99756FU
            && f.value() == 0x807889A6U && g.value() == 0x7F409920U) {
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

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
    d = a - b;
    e = b - a;
    f = c - b;
    g = a - c;

    if (d.value() == 0x7F8B897EU && e.value() == 0x80747682U
        && f.value() == 0x80689423U && g.value() == 0x7FA2984EU) {
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

    a = Posit::from_bits(0x6F10A532U); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665U); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBCU); // Posit -4470.0166015625
    d = a * b;
    e = b * a;
    f = c * b;
    g = a * c;

    if (d.value() == 0x7EDAD7EDU && e.value() == 0x7EDAD7EDU
        && f.value() == 0x8087DEE8U && g.value() == 0x8209467BU) {
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

    a = Posit::from_bits(0x6F10A532U); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665U); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBCU); // Posit -4470.0166015625
    d = a / b;
    e = b / a;
    f = c / b;
    g = a / c;
    h = a / zero;

    if (d.value() == 0x1065495cU && e.value() == 0x6f47a910U
        && f.value() == 0xdd22e2b3U && g.value() == 0xe186b030U
        && h.value() == 0x80000000U) {
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

    a = Posit::from_bits(0x6F10A532U); // Posit  226.08066177368164
    b = Posit::from_bits(0x7B9B7665U); // Posit  52667.197265625
    c = Posit::from_bits(0x87E89FBCU); // Posit -4470.0166015625
    d = Posit::sqrt(a);
    e = Posit::sqrt(b);
    f = Posit::sqrt(c);

    if (d.value() == 0x5F0935EAU && e.value() == 0x6F2BF261U
        && f.value() == 0x80000000U) {
        printf("PSQRT test_ol OK\n");
        return 0;
    }
    else {
        printf("PSQRT test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value());
        return 1;
    }
}

int p32min_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
    d = Posit::min(a, b);
    e = Posit::min(b, a);
    f = Posit::min(c, a);
    g = Posit::min(c, c);

    if (d.value() == 0x7F6EC2BFU && e.value() == 0x7F6EC2BFU
        && f.value() == 0x806E6C7BU && g.value() == 0x806E6C7BU) {
        printf("PMIN test_ol OK\n");
        return 0;
    }
    else {
        printf("PMIN test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32max_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
    d = Posit::max(a, b);
    e = Posit::max(b, a);
    f = Posit::max(c, a);
    g = Posit::max(c, c);

    if (d.value() == 0x7F939D17U && e.value() == 0x7F939D17U
        && f.value() == 0x7F939D17U && g.value() == 0x806E6C7BU) {
        printf("PMAX test_ol OK\n");
        return 0;
    }
    else {
        printf("PMAX test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p32eq_test_ol() {
    Posit a, b, c;
    bool d, e, f;

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
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

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
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

    a = Posit::from_bits(0x7F939D17U); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BFU); // Posit  196128704
    c = Posit::from_bits(0x806E6C7BU); // Posit -589761024
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

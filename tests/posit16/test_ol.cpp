#include <stdio.h>

#include "test_ol.hpp"

#include "posit.hpp"

int p16add_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F94U);
    b = Posit::from_bits(0x7F6FU);
    c = Posit::from_bits(0x806EU);
    d = a + b;
    e = b + a;
    f = c + b;
    g = a + c;

    if (d.value() == 0x7F9AU && e.value() == 0x7F9AU
            && f.value() == 0x8078U && g.value() == 0x7F40U) {
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

int p16sub_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F94U);
    b = Posit::from_bits(0x7F6FU);
    c = Posit::from_bits(0x806EU);
    d = a - b;
    e = b - a;
    f = c - b;
    g = a - c;

    if (d.value() == 0x7F8CU && e.value() == 0x8074U
        && f.value() == 0x8068U && g.value() == 0x7FA3U) {
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

int p16mul_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x6F12U);
    b = Posit::from_bits(0x7B9BU);
    c = Posit::from_bits(0x87E9U);
    d = a * b;
    e = b * a;
    f = c * b;
    g = a * c;

    if (d.value() == 0x7EDBU && e.value() == 0x7EDBU
        && f.value() == 0x8088U && g.value() == 0x8209U) {
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

int p16div_test_ol() {
    Posit a, b, c, d, e, f, g, h, zero;

    zero = Posit::from_bits(0);

    a = Posit::from_bits(0x6F11U);
    b = Posit::from_bits(0x7B9BU);
    c = Posit::from_bits(0x87E9U);
    d = a / b;
    e = b / a;
    f = c / b;
    g = a / c;
    h = a / zero;

    if (d.value() == 0x1067U && e.value() == 0x6F45U
        && f.value() == 0xDD24U && g.value() == 0xE184U
        && h.value() == 0x8000U) {
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

int p16sqrt_test_ol() {
    Posit a, b, c, d, e, f;

    a = Posit::from_bits(0x6F11U);  // Posit  226.125
    b = Posit::from_bits(0x7B9BU);  // Posit  52608
    c = Posit::from_bits(0x87E9U);  // Posit -4464
    d = Posit::sqrt(a);
    e = Posit::sqrt(b);
    f = Posit::sqrt(c);

    if (d.value() == 0x5F0AU && e.value() == 0x6F2BU
            && f.value() == 0x8000U) {
        printf("PSQRT test_ol OK\n");
        return 0;
    } else {
        printf("PSQRT test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value());
        return 1;
    }
}

int p16min_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F94U);  // Posit  671088640
    b = Posit::from_bits(0x7F6FU);  // Posit  197132288
    c = Posit::from_bits(0x806EU);  // Posit -603979776`
    d = Posit::min(a, b);
    e = Posit::min(b, a);
    f = Posit::min(c, a);
    g = Posit::min(c, c);

    if (d.value() == 0x7F6FU && e.value() == 0x7F6FU
            && f.value() == 0x806EU && g.value() == 0x806EU) {
        printf("PMIN test_ol OK\n");
        return 0;
    } else {
        printf("PMIN test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p16max_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F94U);  // Posit  671088640
    b = Posit::from_bits(0x7F6FU);  // Posit  197132288
    c = Posit::from_bits(0x806EU);  // Posit -603979776
    d = Posit::max(a, b);
    e = Posit::max(b, a);
    f = Posit::max(c, a);
    g = Posit::max(c, c);

    if (d.value() == 0x7F94U && e.value() == 0x7F94U
            && f.value() == 0x7F94U && g.value() == 0x806EU) {
        printf("PMAX test_ol OK\n");
        return 0;
    } else {
        printf("PMAX test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d.value(),
            e.value(), f.value(), g.value());
        return 1;
    }
}

int p16eq_test_ol() {
    Posit a, b, c;
    bool d, e, f;

    a = Posit::from_bits(0x7F94U);
    b = Posit::from_bits(0x7F6FU);
    c = Posit::from_bits(0x806EU);
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

int p16lt_test_ol() {
    Posit a, b, c;
    bool d, e, f, g, h;

    a = Posit::from_bits(0x7F94U);
    b = Posit::from_bits(0x7F6FU);
    c = Posit::from_bits(0x806EU);
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

int p16le_test_ol() {
    Posit a, b, c;
    bool d, e, f, g;

    a = Posit::from_bits(0x7F94U);
    b = Posit::from_bits(0x7F6FU);
    c = Posit::from_bits(0x806EU);
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

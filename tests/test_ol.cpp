#include <stdio.h>

#include "posit.hpp"

#include "test_ol.hpp"

int padd_test_ol() {
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

int psub_test_ol() {
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

int pmul_test_ol() {
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

int pdiv_test_ol() {
    Posit a, b, c, d, e, f, g, h, zero;

    zero = Posit(0); // convert from int 0

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

int pcvtws_test_ol() {  // Pos to int
    Posit a, b, c;
    int32_t d, e, f;

    a = Posit::from_bits(0x7F939D17);
    b = Posit::from_bits(0x7F6EC2BF);
    c = Posit::from_bits(0x806E6C7B);
    d = (int32_t)(a);
    e = (int32_t)(b);
    f = (int32_t)(c);

    if (d == 658124288 && e == 196128704 && f == -589761024) {
        printf("PCVTWS test_ol OK\n");
        return 0;
    }
    else {
        printf("PCVTWS test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d, e, f);
        return 1;
    }
}

int pcvtwus_test_ol() {  // Pos to unsigned int
    Posit a, b, c;
    uint32_t d, e, f;

    a = Posit::from_bits(0x7FB87B7D);
    b = Posit::from_bits(0x7F6EC2BF);
    c = Posit::from_bits(0x806E6C7B);
    d = (uint32_t)(a);
    e = (uint32_t)(b);
    f = (uint32_t)(c);

    if (d == 3285968896 && e == 196128704 && f == 0) {
        printf("PCVTWUS test_ol OK\n");
        return 0;
    }
    else {
        printf("PCVTWUS test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a.value(), b.value(), c.value(), d, e, f);
        return 1;
    }
}

int pcvtsw_test_ol() {  // Int to pos
    int32_t a, b, c;
    Posit d, e, f;

    a = 658124290;  // Round -> 658124288 (Posit 0x7F939D17)
    b = 196128700;  // Round -> 196128704 (Posit 0x7F6EC2BF)
    c = -589761023; // Round -> -589761024 (Posit 0x806E6C7B)
    d = Posit(a);
    e = Posit(b);
    f = Posit(c);

    if (d.value() == 0x7F939D17 && e.value() == 0x7F6EC2BF
        && f.value() == 0x806E6C7B) {
        printf("PCVTSW test_ol OK\n");
        return 0;
    }
    else {
        printf("PCVTSW test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d.value(), e.value(), f.value());
        return 1;
    }
}

int pcvtswu_test_ol() {  // Unsigned int to pos
    uint32_t a, b, c;
    Posit d, e, f;

    a = 3285968897; // Round -> 3285968896 (Posit 0x7FB87B7D)
    b = 196128700;  // Round -> 196128704 (Posit 0x7F6EC2BF)
    c = 0;          // Round -> 0 (Posit 0x00000000)
    d = Posit(a);
    e = Posit(b);
    f = Posit(c);

    if (d.value() == 0x7FB87B7D && e.value() == 0x7F6EC2BF && f.value() == 0) {
        printf("PCVTSWU test_ol OK\n");
        return 0;
    }
    else {
        printf("PCVTSWU test_ol FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d.value(), e.value(), f.value());
        return 1;
    }
}

int peq_test_ol() {
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

int plt_test_ol() {
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

int ple_test_ol() {
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

#include <stdio.h>

extern "C" {
    #include <coprosit_cpu.h>
}

#include "posit.hpp"

// FUSESOC --flag=use_posit32
#define POSIT_BITS 32

volatile int posit_ok;
volatile int posit_done;

int padd_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = padd(a, b);
    e = padd(b, a);
    f = padd(c, b);
    g = padd(a, c);

    if (d == 0x7F99756F && e == 0x7F99756F
            && f == 0x807889A6 && g == 0x7F409920) {
        printf("PADD test OK\n");
        return 0;
    }
    else {
        printf("PADD test FAIL - Values: %x %x %x %x %x %x %x\n",
                a, b, c, d, e, f, g);
        return 1;
    }
}

int padd_test_ol() {
    Posit a, b, c, d, e, f, g;

    a = Posit::from_bits(0x7F939D17); // Posit  658124288
    b = Posit::from_bits(0x7F6EC2BF); // Posit  196128704
    c = Posit::from_bits(0x806E6C7B); // Posit -589761024
    d = a + b;
    e = b + a;
    f = c + b;
    g = a + c;

    if (d.value == 0x7F99756F && e.value == 0x7F99756F
            && f.value == 0x807889A6 && g.value == 0x7F409920) {
        printf("PADD test_ol OK\n");
        return 0;
    }
    else {
        printf("PADD test_ol FAIL - Values: %x %x %x %x %x %x %x\n",
                a.value, b.value, c.value, d.value, e.value, f.value, g.value);
        return 1;
    }
}

int psub_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = psub(a, b);
    e = psub(b, a);
    f = psub(c, b);
    g = psub(a, c);

    if (d == 0x7F8B897E && e == 0x80747682
        && f == 0x80689423 && g == 0x7FA2984E) {
        printf("PSUB test OK\n");
        return 0;
    }
    else {
        printf("PSUB test FAIL - Values: %x %x %x %x %x %x %x\n",
            a, b, c, d, e, f, g);
        return 1;
    }
}

int pmul_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x6F10A532; // Posit  226.08066177368164
    b = 0x7B9B7665; // Posit  52667.197265625
    c = 0x87E89FBC; // Posit -4470.0166015625
    d = pmul(a, b);
    e = pmul(b, a);
    f = pmul(c, b);
    g = pmul(a, c);

    if (d == 0x7EDAD7ED && e == 0x7EDAD7ED
        && f == 0x8087DEE8 && g == 0x8209467B) {
        printf("PMUL test OK\n");
        return 0;
    }
    else {
        printf("PMUL test FAIL - Values: %x %x %x %x %x %x %x\n",
                a, b, c, d, e, f, g);
        return 1;
    }
}

int pdiv_test() {
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

    if (d == 0x1065495c && e == 0x6f47a910
        && f == 0xdd22e2b3 && g == 0xe186b030 && h == 0x80000000) {
        printf("PDIV test OK\n");
        return 0;
    }
    else {
        printf("PDIV test FAIL - Values: %x %x %x %x %x %x %x %x\n",
                a, b, c, d, e, f, g, h);
        return 1;
    }
}

int psqrt_test() {
    posit_t a, b, c, d, e, f;

    a = 0x6F10A532; // Posit  226.08066177368164
    b = 0x7B9B7665; // Posit  52667.197265625
    c = 0x87E89FBC; // Posit -4470.0166015625
    d = psqrt(a);
    e = psqrt(b);
    f = psqrt(c);

    if (d == 0x5F0935EA && e == 0x6F2BF261 && f == 0x80000000) {
        printf("PSQRT test OK\n");
        return 0;
    }
    else {
        printf("PSQRT test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int pmin_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = pmin(a, b);
    e = pmin(b, a);
    f = pmin(c, a);
    g = pmin(c, c);

    if (d == 0x7F6EC2BF && e == 0x7F6EC2BF
        && f == 0x806E6C7B && g == 0x806E6C7B) {
        printf("PMIN test OK\n");
        return 0;
    }
    else {
        printf("PMIN test FAIL - Values: %x %x %x %x %x %x %x\n",
               a, b, c, d, e, f, g);
        return 1;
    }
}

int pmax_test() {
    posit_t a, b, c, d, e, f, g;

    a = 0x7F939D17; // Posit  658124288
    b = 0x7F6EC2BF; // Posit  196128704
    c = 0x806E6C7B; // Posit -589761024
    d = pmax(a, b);
    e = pmax(b, a);
    f = pmax(c, a);
    g = pmax(c, c);

    if (d == 0x7F939D17 && e == 0x7F939D17
        && f == 0x7F939D17 && g == 0x806E6C7B) {
        printf("PMAX test OK\n");
        return 0;
    }
    else {
        printf("PMAX test FAIL - Values: %x %x %x %x %x %x %x\n",
               a, b, c, d, e, f, g);
        return 1;
    }
}

int pcvtws_test() {  // Pos to int
    posit_t a, b, c;
    int32_t d, e, f;

    a = 0x7F939D17;
    b = 0x7F6EC2BF;
    c = 0x806E6C7B;
    d = pcvtws(a);
    e = pcvtws(b);
    f = pcvtws(c);

    if (d == 658124288 && e == 196128704 && f == -589761024) {
        printf("PCVTWS test OK\n");
        return 0;
    }
    else {
        printf("PCVTWS test FAIL - Values: %x %x %x %x %x %x\n",
               a, b, c, d, e, f);
        return 1;
    }
}

int pcvtwus_test() {  // Pos to unsigned int
    posit_t a, b, c;
    uint32_t d, e, f;

    a = 0x7FB87B7D;
    b = 0x7F6EC2BF;
    c = 0x806E6C7B;
    d = pcvtwus(a);
    e = pcvtwus(b);
    f = pcvtwus(c);

    if (d == 3285968896 && e == 196128704 && f == 0) {
        printf("PCVTWUS test OK\n");
        return 0;
    }
    else {
        printf("PCVTWUS test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int pcvtsw_test() {  // Int to pos
    int32_t a, b, c;
    posit_t d, e, f;

    a = 658124290;  // Round -> 658124288 (Posit 0x7F939D17)
    b = 196128700;  // Round -> 196128704 (Posit 0x7F6EC2BF)
    c = -589761023; // Round -> -589761024 (Posit 0x806E6C7B)
    d = pcvtsw(a);
    e = pcvtsw(b);
    f = pcvtsw(c);

    if (d == 0x7F939D17 && e == 0x7F6EC2BF && f == 0x806E6C7B) {
        printf("PCVTSW test OK\n");
        return 0;
    }
    else {
        printf("PCVTSW test FAIL - Values: %x %x %x %x %x %x\n",
               a, b, c, d, e, f);
        return 1;
    }
}

int pcvtswu_test() {  // Unsigned int to pos
    uint32_t a, b, c;
    posit_t d, e, f;

    a = 3285968897; // Round -> 3285968896 (Posit 0x7FB87B7D)
    b = 196128700;  // Round -> 196128704 (Posit 0x7F6EC2BF)
    c = 0;          // Round -> 0 (Posit 0x00000000)
    d = pcvtswu(a);
    e = pcvtswu(b);
    f = pcvtswu(c);

    if (d == 0x7FB87B7D && e == 0x7F6EC2BF && f == 0) {
        printf("PCVTSWU test OK\n");
        return 0;
    }
    else {
        printf("PCVTSWU test FAIL - Values: %x %x %x %x %x %x\n",
            a, b, c, d, e, f);
        return 1;
    }
}

int peq_test() {
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

int plt_test() {
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

int ple_test() {
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

void posit32_tests() {
    int result = 0;

    result += padd_test();
    result += padd_test_ol();
    result += psub_test();
    result += pmul_test();
    result += pdiv_test();
    result += psqrt_test();
    result += pmin_test();
    result += pmax_test();
    result += pcvtws_test();
    result += pcvtwus_test();
    result += pcvtsw_test();
    result += pcvtswu_test();
    result += peq_test();
    result += plt_test();
    result += ple_test();

    posit_ok = result == 0;
    posit_done = 1;
}

int main() {
    posit_ok = 1;

    coprosit_launch_cpu((coprosit_start_function_ptr_t)&posit32_tests);
    while (!posit_done);
    coprosit_reset_cpu();

    return 1 - posit_ok;
}

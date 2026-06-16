// main.c
// Run tests on base wrapper library

#include <coprosit_cpu.h>

#ifdef TEST_POSIT16
#include "tests/posit16/test_base.h"
#else
#include "tests/posit32/test_base.h"
#endif

volatile int posit_ok;
volatile int posit_done;

void posit_base_tests() {
    int result = 0;

    #ifdef TEST_POSIT16
    result += p16add_test();
    result += p16sub_test();
    result += p16mul_test();
    result += p16div_test();
    result += p16sqrt_test();
    result += p16min_test();
    result += p16max_test();
    result += p16eq_test();
    result += p16lt_test();
    result += p16le_test();
    #else
    result += p32add_test();
    result += p32sub_test();
    result += p32mul_test();
    result += p32div_test();
    result += p32sqrt_test();
    result += p32min_test();
    result += p32max_test();
    result += p32eq_test();
    result += p32lt_test();
    result += p32le_test();
    #endif

    posit_ok = result != 0 ? 1 : 0;
    posit_done = 1;
}

int main() {
    posit_ok = 1;

    coprosit_launch_cpu((coprosit_start_function_ptr_t)&posit_base_tests);
    while (!posit_done);
    coprosit_reset_cpu();

    return 1 - posit_ok;
}

// main.cpp
// Run tests on full operator overload library

extern "C" {
    #include <coprosit_cpu.h>
    #ifdef TEST_POSIT16
    #include "tests/posit16/test_base.h"
    #else
    #include "tests/posit32/test_base.h"
    #endif
}

#ifdef TEST_POSIT16
#include "tests/posit16/test_ol.hpp"
#else
#include "tests/posit32/test_ol.hpp"
#endif

volatile int posit_ok;
volatile int posit_done;

void posit_full_tests() {
    int result = 0;

    // run base tests
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

    // run operator overload tests
    #ifdef TEST_POSIT16
    result += p16add_test_ol();
    result += p16sub_test_ol();
    result += p16mul_test_ol();
    result += p16div_test_ol();
    result += p16sqrt_test_ol();
    result += p16min_test_ol();
    result += p16max_test_ol();
    result += p16eq_test_ol();
    result += p16lt_test_ol();
    result += p16le_test_ol();
    #else
    result += p32add_test_ol();
    result += p32sub_test_ol();
    result += p32mul_test_ol();
    result += p32div_test_ol();
    result += p32sqrt_test_ol();
    result += p32min_test_ol();
    result += p32max_test_ol();
    result += p32eq_test_ol();
    result += p32lt_test_ol();
    result += p32le_test_ol();
    #endif

    posit_ok = result != 0 ? 1 : 0;
    posit_done = 1;
}

int main() {
    posit_ok = 1;

    coprosit_launch_cpu((coprosit_start_function_ptr_t)&posit_full_tests);
    while (!posit_done);
    coprosit_reset_cpu();

    return 1 - posit_ok;
}

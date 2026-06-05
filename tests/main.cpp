// main.cpp
// Run tests on full operator overload library

extern "C" {
    #include <coprosit_cpu.h>
    #include "test_base.h"
}

#include "test_ol.hpp"

volatile int posit_ok;
volatile int posit_done;

void posit32_full_tests() {
    int result = 0;

    // run base tests
    result += padd_test();
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

    // run operator overload tests
    result += padd_test_ol();
    result += psub_test_ol();
    result += pmul_test_ol();
    result += pdiv_test_ol();
    result += pcvtws_test_ol();
    result += pcvtwus_test_ol();
    result += pcvtsw_test_ol();
    result += pcvtswu_test_ol();
    result += peq_test_ol();
    result += plt_test_ol();
    result += ple_test_ol();

    posit_ok = result != 0 ? 1 : 0;
    posit_done = 1;
}

int main() {
    posit_ok = 1;

    coprosit_launch_cpu((coprosit_start_function_ptr_t)&posit32_full_tests);
    while (!posit_done);
    coprosit_reset_cpu();

    return 1 - posit_ok;
}

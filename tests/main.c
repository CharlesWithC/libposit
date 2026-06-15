// main.c
// Run tests on base wrapper library

#include <coprosit_cpu.h>

#include "test_base.h"

volatile int posit_ok;
volatile int posit_done;

void posit32_base_tests() {
    int result = 0;

    result += padd_test();
    result += psub_test();
    result += pmul_test();
    result += pdiv_test();
    result += psqrt_test();
    result += pmin_test();
    result += pmax_test();
    result += peq_test();
    result += plt_test();
    result += ple_test();

    posit_ok = result != 0 ? 1 : 0;
    posit_done = 1;
}

int main() {
    posit_ok = 1;

    coprosit_launch_cpu((coprosit_start_function_ptr_t)&posit32_base_tests);
    while (!posit_done);
    coprosit_reset_cpu();

    return 1 - posit_ok;
}

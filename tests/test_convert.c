#include <stdio.h>

#include "softposit/posit16.h"
#include "softposit/posit32.h"

int main() {
    uint32_t aa, bb, cc, dd, ee, ff;
    double a, b, c, d, e, f;

    aa = convertDoubleToP32(658124288);
    bb = convertDoubleToP32(196128704);
    cc = convertDoubleToP32(-589761024);
    dd = convertDoubleToP32(226.080662);
    ee = convertDoubleToP32(52667.197266);
    ff = convertDoubleToP32(-4470.016602);
    printf("%x %x %x %x %x %x\n", aa, bb, cc, dd, ee, ff);

    a = convertP32ToDouble(0x7F939D17U);
    b = convertP32ToDouble(0x7F6EC2BFU);
    c = convertP32ToDouble(0x806E6C7BU);
    d = convertP32ToDouble(0x6F10A532U);
    e = convertP32ToDouble(0x7B9B7665U);
    f = convertP32ToDouble(0x87E89FBCU);
    printf("%lf %lf %lf %lf %lf %lf\n", a, b, c, d, e, f);

    aa = convertDoubleToP16(671088640);
    bb = convertDoubleToP16(197132288);
    cc = convertDoubleToP16(-603979776);
    dd = convertDoubleToP16(226.125);
    ee = convertDoubleToP16(52608);
    ff = convertDoubleToP16(-4464);
    printf("%x %x %x %x %x %x\n", aa, bb, cc, dd, ee, ff);

    a = convertP16ToDouble(0x7F94U);
    b = convertP16ToDouble(0x7F6FU);
    c = convertP16ToDouble(0x806EU);
    d = convertP16ToDouble(0x6F11U);
    e = convertP16ToDouble(0x7B9BU);
    f = convertP16ToDouble(0x87E9U);
    printf("%lf %lf %lf %lf %lf %lf\n", a, b, c, d, e, f);

    return 0;
}

// posit.hpp

#ifndef POSIT_HPP
#define POSIT_HPP

#include "posit.h"

class Posit {
    posit_t v; // private field, use `value` method

public:
    explicit Posit() { }

    // default constructor: convert int/uint to posit
    // this is similar to universal numbers behavior
    // for float, consider `constexpr` with `universal`
    // which should be coded at application level
    explicit Posit(INT_TYPE x) {
        v = pcvtsw(x);
    }
    explicit Posit(UINT_TYPE x) {
        v = pcvtswu(x);
    }

    posit_t value() {
        // move value from PosReg to GPR before allowing direct usage
        // read comment in `posit.h` for more information
        return pmvxw(v);
    }

    posit_t value_unsafe() {
        // access value directly; this is potentially unsafe
        return v;
    }

    // call `from_bits` to directly set posit numbers
    static Posit from_bits(posit_t x){
        Posit p;
        p.v = x; // do not call pmvwx and let llvm do that optimization
        return p;
    }

    explicit operator INT_TYPE() const {
        return pcvtws(v);
    }

    explicit operator UINT_TYPE() const {
        return pcvtwus(v);
    }

    Posit& operator+=(Posit y) {
        v = padd(v, y.v);
        return *this;
    }

    Posit& operator-=(Posit y) {
        v = psub(v, y.v);
        return *this;
    }

    Posit& operator*=(Posit y) {
        v = pmul(v, y.v);
        return *this;
    }

    Posit& operator/=(Posit y) {
        v = pdiv(v, y.v);
        return *this;
    }

    friend inline Posit operator+(Posit x, Posit y) { return x += y; }
    friend inline Posit operator-(Posit x, Posit y) { return x -= y; }
    friend inline Posit operator*(Posit x, Posit y) { return x *= y; }
    friend inline Posit operator/(Posit x, Posit y) { return x /= y; }

    friend inline bool operator==(Posit x, Posit y) { return peq(x.v, y.v); }
    friend inline bool operator< (Posit x, Posit y) { return plt(x.v, y.v); }
    friend inline bool operator<=(Posit x, Posit y) { return ple(x.v, y.v); }

    friend inline bool operator> (Posit x, Posit y) { return !ple(x.v, y.v); }
    friend inline bool operator>=(Posit x, Posit y) { return !plt(x.v, y.v); }
};

#endif

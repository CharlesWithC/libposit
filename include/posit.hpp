// posit.hpp

#ifndef POSIT_HPP
#define POSIT_HPP

#include "posit.h"

// NOTE: It seems there is hardware latency issue on plw/psw/pmv.w.x/pmv.x.w
// Various approaches of load/store/copy were attempted, and it was observed
// that using `pmv.w.x` to load a posit value from integer in GPR, and using
// `psw` to store a posit value to integer in memory is the only combination
// that works for both posit16 and posit32. The cause is to be investigated.

class Posit {
    posit_t v; // private field, use `value` method

public:
    explicit Posit() { }

    posit_t value() {
        return psw(v);
    }

    // call `from_bits` to directly set posit numbers
    static Posit from_bits(posit_t x){
        Posit p;
        p.v = pmvwx(x);
        return p;
    }

    static Posit min(Posit x, Posit y){
        Posit p;
        p.v = pmin(x.v, y.v);
        return p;
    }

    static Posit max(Posit x, Posit y){
        Posit p;
        p.v = pmax(x.v, y.v);
        return p;
    }

    static Posit sqrt(Posit x){
        Posit p;
        p.v = psqrt(x.v);
        return p;
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

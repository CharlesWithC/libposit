// posit.hpp

#ifndef POSIT_HPP
#define POSIT_HPP

#include "posit.h"

#ifdef USE_CONSTEVAL // force compile-time evaluation
#define CONSTEXPR consteval
#else
#define CONSTEXPR constexpr
#endif

// NOTE: It seems there is hardware latency issue on pmvxw.
//
// Whether we let LLVM auto decide when to use pmvxw, or we manually call pmvxw
// on .value(), we observe similar latency-related issues, where raw posit data
// is not always immediately available, and may be overwritten when accessed
// later. The current workaround is to use psw to route data through memory
// when accessing raw posit values, which prevents LLVM from using pmvxw
// shortcut to move data to GPR. The hardware should be investigated to
// determine the exact cause of this issue.
//
// Side note:
// Using psw also avoids sign bit extensions in posit16 when dealing with GPR.

class Posit {
    posit_t v; // private field, use `value` method

public:
    Posit() : v(0) { }
    explicit CONSTEXPR Posit(double x) : v(double2posit(x)) { }
    explicit CONSTEXPR Posit(float x)  : v(double2posit(static_cast<double>(x))) { }

    operator double() const { return posit2double(v); }
    operator float()  const { return static_cast<float>(posit2double(v)); }

    posit_t value() {
        return psw(v);
    }

    // call `from_bits` to directly set posit numbers
    static Posit from_bits(posit_t x){
        Posit p;
        p.v = x;
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

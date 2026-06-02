// posit.hpp

#ifndef POSIT_HPP
#define POSIT_HPP

#include "posit.h"

struct Posit {
    posit_t value;

    explicit Posit() { }

    // default constructor: convert int/uint to posit
    // this is similar to universal numbers behavior
    // for float, consider `constexpr` with `universal`
    // which should be coded at application level
    explicit Posit(INT_TYPE x) {
        value = pcvtsw(x);
    }
    explicit Posit(UINT_TYPE x) {
        value = pcvtswu(x);
    }

    // call `from_bits` to directly set posit numbers
    static Posit from_bits(posit_t x){
        Posit p;
        p.value = x;
        return p;
    }

    explicit operator INT_TYPE() const {
        return pcvtws(value);
    }

    explicit operator UINT_TYPE() const {
        return pcvtwus(value);
    }
};

static inline Posit& operator+=(Posit& x, Posit y) {
    x.value = padd(x.value, y.value);
    return x;
}

static inline Posit operator+(Posit x, Posit y) {
    return x += y;
}

static inline Posit& operator-=(Posit& x, Posit y) {
    x.value = psub(x.value, y.value);
    return x;
}

static inline Posit operator-(Posit x, Posit y) {
    return x -= y;
}

static inline Posit& operator*=(Posit& x, Posit y) {
    x.value = pmul(x.value, y.value);
    return x;
}

static inline Posit operator*(Posit x, Posit y) {
    return x *= y;
}

static inline Posit& operator/=(Posit& x, Posit y) {
    x.value = pdiv(x.value, y.value);
    return x;
}

static inline Posit operator/(Posit x, Posit y) {
    return x /= y;
}

static inline bool operator==(Posit x, Posit y) {
    return peq(x.value, y.value);
}

static inline bool operator<(Posit x, Posit y) {
    return plt(x.value, y.value);
}

static inline bool operator>(Posit x, Posit y) {
    return !ple(x.value, y.value);
}

static inline bool operator<=(Posit x, Posit y) {
    return ple(x.value, y.value);
}

static inline bool operator>=(Posit x, Posit y) {
    return !plt(x.value, y.value);
}

#endif

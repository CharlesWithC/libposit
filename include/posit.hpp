// posit.hpp

#ifndef POSIT_HPP
#define POSIT_HPP

#include "posit.h"

struct Posit {
    posit_t value;

    Posit() { }

    // default assignment behavior: convert int to posit
    // this is similar to universal numbers behavior
    // for float, consider `constexpr` with `universal`
    // which should be coded at application level
    Posit(INT_TYPE x) {
        value = pcvtsw(x);
    }

    // call `from_bits` to directly set posit numbers
    static Posit from_bits(posit_t x){
        Posit p;
        p.value = x;
        return p;
    }
};

static inline Posit& operator+=(Posit& x, Posit y) {
    x.value = padd(x.value, y.value);
    return x;
}

static inline Posit operator+(Posit x, Posit y) {
    return x += y;
}

// if comparing directly with a non-posit variable
// the other variable would be assumed as int and converted to posit
static inline bool operator==(Posit x, Posit y) {
    return peq(x.value, y.value);
}

#endif

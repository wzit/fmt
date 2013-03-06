#pragma once

/*
 * Header for static_pattern class.
 * That must be refactored to pattern in future.
 */

#include "static_string.hpp"
#include "check_pattern.hpp"


namespace fmt {


/*
 * Static wrapper for pattern class.
 */
class static_pattern {

public:

    /* Save string and check its validity */
    template <unsigned N>
    constexpr static_pattern(const char (&strn)[N]);

    /* Problems here -- no destructors for literal types */
    // ~static_pattern();

    /* Given arguments, return the string */
    template <typename ... Types>
    std::string format(Types ... args) const;

private:

    mutable static_string str;

    bool check;

    mutable pattern *pat;
};


} // namespace fmt


/* Implementation */


namespace fmt {


template <unsigned N>
constexpr static_pattern::static_pattern(const char (&strn)[N])
    : str(strn), check(check_pattern(strn)), pat(nullptr) {

}


// static_pattern::~static_pattern() {
//     if (pat != nullptr) {
//         delete pat;
//     }
// }


template <typename ... Types>
std::string static_pattern::format(Types ... args) const {
    if (pat == nullptr) {
        pat = new pattern(str.c_str());
    }
    return pat->format(args ...);
}


} // namespace fmt

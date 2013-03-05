#pragma once

/*
 * Header for static_pattern class.
 * That must be refactored to pattern in future.
 */

#include "static_string.hpp"
#include "check_pattern.hpp"


namespace fmt {


class static_pattern {

public:

    /* Save string and check its validity */
    constexpr static_pattern(static_string pat);

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


constexpr static_pattern::static_pattern(static_string strn)
    : str(strn), check(check_pattern(strn)), pat(nullptr) {

}


template <typename ... Types>
std::string static_pattern::format(Types ... args) const {
    if (pat == nullptr) {
        pat = new pattern(str.c_str());
    }
    return pat->format(args ...);
}


} // namespace fmt

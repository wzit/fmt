#pragma once

#include <stdexcept>

#include "static_string.hpp"


namespace fmt {


/* Check pattern correctness. */
constexpr bool check_pattern(static_string pat);


/* Return #'}' - #'{' in suffix staring at from.
 * Throw if the balance becomes negative. */
constexpr int check_parity(static_string pat, unsigned from=0);


} // namespace fmt


/* Implementation */


namespace fmt {


constexpr bool check_pattern(static_string pat) {
    return check_parity(pat) == 0 ? true : throw std::logic_error("Wrong braces balance in format string");
}


constexpr int check_parity(static_string pat, unsigned from) {
    return from == pat.length() ?
                0
        :  pat[from] == '{' ?
                ( check_parity(pat, from+1) > 0 ?
                    check_parity(pat, from+1) - 1
                    : throw std::logic_error("Unmached '{' in format string"))
        :  pat[from] == '}' ?
                check_parity(pat, from+1) + 1
        :       check_parity(pat, from+1);
}


} // namespace fmt

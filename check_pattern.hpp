#pragma once

#include "static_string.hpp"


namespace fmt {


constexpr int check_parity(static_string pat, unsigned from=0) {
    return from == pat.length() ?
                0
        :  pat[from] == '{' ?
                check_parity(pat, from+1) + 1
        :  pat[from] == '}' ?
                check_parity(pat, from+1) - 1
        :       check_parity(pat, from+1);
}


constexpr bool check_pattern(static_string pat) {
    return check_parity(pat) == 0 ? true : throw;
}


} // namespace fmt

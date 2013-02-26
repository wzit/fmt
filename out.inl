/*
 * Implementation for out function
 */

#include <iostream>


namespace fmt {


template <typename ... Types>
void out(std::string pattern_str, Types ... args) {
    std::cout << pattern(pattern_str).format(args...);
}


} // namespace fmt

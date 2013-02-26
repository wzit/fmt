/*
 * Implementation for out and err functions
 */

#include <iostream>


namespace fmt {


template <typename ... Types>
void out(std::string pattern_str, Types ... args) {
    std::cout << pattern(pattern_str).format(args...);
}


template <typename ... Types>
void err(std::string pattern_str, Types ... args) {
    std::cerr << pattern(pattern_str).format(args...);
}


} // namespace fmt

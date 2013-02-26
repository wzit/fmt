/*
 * Implementation for out and err functions
 */

#include <iostream>


namespace fmt {


template <typename ... Types>
void out(const std::string& pat, Types ... args) {
    std::cout << pattern(pat).format(args...);
}


template <typename ... Types>
void err(const std::string& pat, Types ... args) {
    std::cerr << pattern(pat).format(args...);
}


} // namespace fmt

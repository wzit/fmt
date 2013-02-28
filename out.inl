/*
 * Implementation for out and err functions
 */

#include <iostream>


namespace fmt {


template <typename ... Types>
void out(const std::string& pat, Types ... args) {
    pattern(pat).out(args...);
}


template <typename ... Types>
void err(const std::string& pat, Types ... args) {
    pattern(pat).err(args...);
}


} // namespace fmt

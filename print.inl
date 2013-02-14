#include <iostream>


namespace fmt {

template <typename Char, typename ... Types>
void print(std::basic_string<Char> pattern, Types ... args) {
    std::cout << Pattern<char>(pattern).format(args...);
}


template <typename ... Types>
void print(const char* pattern, Types ... args) {
    std::cout << Pattern<char>(pattern).format(args...);
}

} // namespace fmt

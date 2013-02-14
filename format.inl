#include <stdexcept>


namespace fmt {

template <typename Char, typename Type>
std::basic_string<Char> format(Type arg) {
    return arg;
}


template <typename Char>
std::basic_string<Char> format(int arg) {
    return std::to_string(arg);
}

} // namespace fmt

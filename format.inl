/*
 * Basic implementations of formatting function.
 */


namespace fmt {


/*
 * Default behaviour for formatting function.
 */
template <typename Char, typename Type>
std::basic_string<Char> format(Type arg) {
    return arg;
}


/*
 * Integer formatting.
 */
template <typename Char>
std::basic_string<Char> format(int arg) {
    return std::to_string(arg);
}

} // namespace fmt

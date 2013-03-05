/*
 * Basic implementations of formatting function.
 */


namespace fmt {


/*
 * Default behaviour for formatting function.
 */
template <typename Char, typename Type>
std::basic_string<Char> format(Type arg, const field<Char>& opt) {
    return arg;
}


/*
 * Integer formatting.
 */
template <typename Char>
std::basic_string<Char> format(int arg, const field<Char>& opt) {
    return std::to_string(arg);
}


/*
 * Unsigned formatting.
 */
template <typename Char>
std::basic_string<Char> format(unsigned arg, const field<Char>& opt) {
    return std::to_string(arg);
}


/*
 * Float formatting.
 */
template <typename Char>
std::basic_string<Char> format(float arg, const field<Char>& opt) {
    return std::to_string(arg);
}


/*
 * Double formatting.
 */
template <typename Char>
std::basic_string<Char> format(double arg, const field<Char>& opt) {
    return std::to_string(arg);
}


} // namespace fmt

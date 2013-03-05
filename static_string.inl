/*
 * Constant expression string implementation
 */


namespace fmt {


template <unsigned N>
constexpr static_string::static_string(const char (&strn)[N])
    : n(N), str(strn) {}


const char* static_string::c_str() {
    return str;
}


constexpr unsigned static_string::length() {
    return n;
}


constexpr char static_string::operator[](unsigned index) {
    return str[index];
}

} // namespace fmt

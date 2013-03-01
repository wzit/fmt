/*
 * Constant expression string implementation
 */


namespace fmt {


template <unsigned N>
constexpr static_string::static_string(const char (&strn)[N])
    : n(N), str(strn) {}


} // namespace fmt

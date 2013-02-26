/*
 * Custom types support demonstration.
 */


/*
 *Class for tests.
 */
struct my_complex {
    int real;
    int imag;
};


// You *must* make this include *before* specializing format function. 
#include "format.hpp"


namespace fmt {
template <typename Char>
std::basic_string<Char> format(const my_complex& arg) {
    return std::to_string(arg.real)
           + " + "
           + std::to_string(arg.imag)
           + "j";
}
} // namespace fmt


#include "fmt.hpp"


int main() {
    my_complex x = {3, 4};
    fmt::out("x = {}\n", x);

    return 0;
}

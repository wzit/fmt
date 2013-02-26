/*
 * A brief instoduction to library usage.
 */


#include <iostream>

#include "fmt.hpp"


// struct my_complex {
//     int real;
//     int imag;
// };

// namespace fmt {

// template <typename Char>
// std::basic_string<Char> format(my_complex arg) {
//     return std::to_string(arg.real)
//            + " + "
//            + std::to_string(arg.imag)
//            + "j";
// }

// }


int main() {
    /* Nice output */
    fmt::out("Roses are {}\nThe answer is {}\n", "green", 41);

    /* Separate formatting from output */
    fmt::pattern pat = "{} equals {}";
    std::cout << pat.format(4, "five") << std::endl;

    /* Custom types support */
    // my_complex x = {3, 4};
    // fmt::out("x = {}", x);

    return 0;
}

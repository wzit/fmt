/*
 * A brief instoduction to library usage.
 */


#include "fmt.hpp"


int main() {
    /* Nice output. */
    fmt::out("Roses are {}\nThe answer is {}\n", "green", 41);

    /* Separate formatting from output. */
    fmt::pattern pat = "{} equals {}\n";
    std::cout << pat.format(4, "five");

    /* Output to stderr in another way. */
    pat.err("pi", 3.14);

    return 0;
}

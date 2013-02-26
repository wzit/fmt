/*
 * A brief instoduction to library usage.
 */


#include "fmt.hpp"


int main() {
    /* Nice output. */
    fmt::out("Roses are {}\nThe answer is {}\n", "green", 41);

    /* Separate formatting from output. */
    fmt::pattern pat = "{} equals {}";
    std::cout << pat.format(4, "five") << std::endl;

    return 0;
}

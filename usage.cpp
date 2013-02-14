#include <iostream>

#include "fmt.hpp"

int main() {

    fmt::print("Roses are {}\nThe answer is {}\n", "green", 41);

    fmt::Pat pattern = "{} equals {}";
    std::cout << pattern.format(4, "five") << std::endl;

    return 0;
}

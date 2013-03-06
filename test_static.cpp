/*
 * A couple of static tests.
 */

#include "fmt.hpp"


using namespace fmt;


template <typename TypeA, typename TypeB>
void assert_equals(TypeA a, TypeB b) {
    if (a != b) {
        err("{} != {}\n", a, b);
        exit(1);
    }
}


void basic_test() {
    constexpr static_pattern hello_pat = "Hello, {}!";

    assert_equals(hello_pat.format("world"), "Hello, world!");
    assert_equals(hello_pat.format(42), "Hello, 42!");

    constexpr static_pattern empty_pat = "No arguments please!";

    assert_equals(empty_pat.format(), "No arguments please!");

    constexpr static_pattern three_pat = "{} + {} = {}";

    assert_equals(three_pat.format(1, 2, 3), "1 + 2 = 3");
    assert_equals(three_pat.format("x", 8, 51), "x + 8 = 51");

    // static_pattern another_bad_pat = "Also wrong {{}!";
    // Runtime error.

    // constexpr static_pattern bad_pat = "Wrong {}}!";
    // Compile-time error.
}


int main()

{
    basic_test();
    out("basic tests ok\n");
    return 0;
}

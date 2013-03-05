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
    constexpr auto hello_pat = static_pattern("Hello, {}!");

    assert_equals(hello_pat.format("world"), "Hello, world!");
    assert_equals(hello_pat.format(42), "Hello, 42!");

    constexpr auto empty_pat = static_pattern("No arguments please!");

    assert_equals(empty_pat.format(), "No arguments please!");

    constexpr auto three_pat = static_pattern("{} + {} = {}");

    assert_equals(three_pat.format(1, 2, 3), "1 + 2 = 3");
    assert_equals(three_pat.format("x", 8, 51), "x + 8 = 51");

    // constexpr auto bad_pat = static_pattern("{{wrong!");
    // Compile-time error.
}


int main()

{
    basic_test();
    out("basic tests ok\n");
    return 0;
}

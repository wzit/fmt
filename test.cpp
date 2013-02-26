/*
 * A couple of tests.
 */

#include "fmt.hpp"

using namespace fmt;


template <typename TypeA, typename TypeB>
void assert_equals(TypeA a, TypeB b) {
    if (a != b) {
        std::cerr << a << " != " << b << std::endl;
        exit(1);
    }
}


void basic_test() {
    auto hello_pat = pattern("Hello, {}!");

    assert_equals(hello_pat.format("world"), "Hello, world!");
    assert_equals(hello_pat.format(42), "Hello, 42!");

    auto empty_pat = pattern("No arguments please!");

    assert_equals(empty_pat.format(), "No arguments please!");

    auto three_pat = pattern("{} + {} = {}");

    assert_equals(three_pat.format(1, 2, 3), "1 + 2 = 3");
    assert_equals(three_pat.format("x", 8, 51), "x + 8 = 51");
}


int main()

{
    basic_test();
    return 0;
}

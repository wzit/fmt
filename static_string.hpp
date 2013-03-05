#pragma once

/*
 * Constant expression string
 */

namespace fmt {


class static_string {

public:

    template <unsigned N>
    constexpr static_string(const char (&strn)[N]);

    const char* c_str();

    constexpr unsigned length();

    constexpr char operator[](unsigned index);

private:

    unsigned n;
    const char *str;

};


} // namespace fmt

#include "static_string.inl"

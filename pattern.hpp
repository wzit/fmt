#pragma once

/*
 * Header for pattern class.
 */

#include <string>
#include <vector>

#include "static_string.hpp"


namespace fmt {


/*
 * Represents format string.
 */
template <typename Char>
class basic_pattern {

public:

    /* Constructs pattern from std string */
    basic_pattern(const static_string& pat);

    /* Support implicit construction from literals */
    template <int N>
    basic_pattern(const Char(&pat)[N]);

    /* Given arguments, return the string */
    template <typename ... Types>
    std::basic_string<Char> format(Types ... args) const;

    /* Output the string to stdout */
    template <typename ... Types>
    void out(Types ... args) const;

    /* Output the string to stderr */
    template <typename ... Types>
    void err(Types ... args) const;

private:

    /* GCC 4.6 doesn't support calling ctor from ctor */
    void init(const static_string& pat);

    template <typename Type, typename ... Types>
    std::basic_string<Char> _format(Type arg, Types ... args) const;

    std::basic_string<Char> _format() const;

    std::vector<std::basic_string<Char>> chunks;

};


/* Typedefs for common char types */
typedef basic_pattern<char> pattern;
typedef basic_pattern<wchar_t> wpattern;


} // namespace fmt


#include "pattern.inl"

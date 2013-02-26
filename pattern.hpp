#pragma once

/*
 * Header for pattern class.
 */

#include <string>
#include <vector>


namespace fmt {


/*
 * Represents format string.
 */
template <typename Char>
class basic_pattern {

public:

    /* Constructs pattern from std string */
    basic_pattern(const std::basic_string<Char>& pat);

    /* Support implicit construction from literals */
    template <int N>
    basic_pattern(const Char(&pat)[N]);

    /* Given arguments, produce the string */
    template <typename ... Types>
    std::basic_string<Char> format(Types ... args);

private:

    template <typename Type, typename ... Types>
    std::basic_string<Char> _format(Type arg, Types ... args);

    std::basic_string<Char> _format();

    std::vector<std::basic_string<Char>> chunks;

};


/* Typedefs for common char types */
typedef basic_pattern<char> pattern;
typedef basic_pattern<wchar_t> wpattern;


} // namespace fmt


#include "pattern.inl"

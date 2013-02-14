#pragma once

#include <string>
#include <vector>


namespace fmt {

template <typename Char>
class Pattern {

public:

    Pattern(const std::basic_string<Char>& pat);
    Pattern(const char* pat);

    template <typename ... Types>
    std::basic_string<Char> format(Types ... args);

private:

    template <typename Type, typename ... Types>
    std::basic_string<Char> _format(Type arg, Types ... args);

    std::basic_string<Char> _format();

    std::vector<std::basic_string<Char>> chunks;

};

typedef Pattern<char> Pat;
typedef Pattern<wchar_t> WPat;

} // namespace fmt

#include "pattern.inl"

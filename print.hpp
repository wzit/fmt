#pragma once

#include "pattern.hpp"


namespace fmt {

template <typename Char, typename ... Types>
void print(std::basic_string<Char> pattern, Types ... args);

} // namespace fmt

#include "print.inl"

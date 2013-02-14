#pragma once

#include <string>


namespace fmt {

template <typename Char, typename Type>
std::basic_string<Char> format(Type arg);

} // namespace fmt

#include "format.inl"

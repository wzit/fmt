#pragma once

/*
 * Declaration of formatting function.
 */

#include <string>

#include "field.hpp"


namespace fmt {


/*
 * Formatting function.
 * Specialize this template to support custom types.
 */
template <typename Char, typename Type>
std::basic_string<Char> format(Type arg, const field<Char>& opt);


} // namespace fmt

#include "format.inl"

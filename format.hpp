#pragma once

/*
 * Declaration of formatting function.
 */

#include <string>


namespace fmt {


/*
 * Formatting function.
 * Specialize this template to support custom types.
 */
template <typename Char, typename Type>
std::basic_string<Char> format(Type arg);


} // namespace fmt

#include "format.inl"

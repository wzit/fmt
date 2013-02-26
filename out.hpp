#pragma once

/*
 * Header for printf-like functionality.
 */

#include "pattern.hpp"


namespace fmt {


/*
 * Printf analogue with fancy formatting.
 */
template <typename Char, typename ... Types>
void out(std::basic_string<Char> pattern, Types ... args);


} // namespace fmt


#include "out.inl"

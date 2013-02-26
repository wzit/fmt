#pragma once

/*
 * Header for printf-like functionality.
 */

#include "pattern.hpp"


namespace fmt {


/*
 * Printf analogues with fancy formatting.
 */

template <typename Char, typename ... Types>
void out(const std::string& pat, Types ... args);


template <typename Char, typename ... Types>
void err(const std::string pat, Types ... args);


} // namespace fmt


#include "out.inl"

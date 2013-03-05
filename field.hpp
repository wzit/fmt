#pragma once

/*
 * Header for field class.
 */

#include <string>


namespace fmt {


/*
 * Parses format field.
 */
template <typename Char>
class field {

public:

    /* Parses the string. */
    field(const std::basic_string<Char>& fi);

private:



};


} // namespace fmt


#include "field.inl"

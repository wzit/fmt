/*
 * Implementation of pattern class.
 */

#include "format.hpp"

#include <iostream>
#include <stdexcept>

namespace fmt {


template <typename Char>
basic_pattern<Char>::basic_pattern(const std::basic_string<Char>& pat) {

    std::string chunk;
    for(auto iter = pat.begin(); iter != pat.end(); ++iter) {
        if(*iter == '{') {
            if(iter + 1 != pat.end() && *(iter + 1) == '{') {
                chunk.push_back('{');
                ++iter;                     // skip second "{"
            }
            else {                          // field begins
                ++iter;
                auto field_start = iter;
                for(; iter != pat.end() && *iter != '}'; ++iter) {}
                if(iter == pat.end()) {
                    throw std::logic_error("No matching '}'");
                }
                else {
                    std::basic_string<Char> field(field_start, iter);
                    chunks.push_back(chunk);
                    chunk.clear();
                }
            }
        }
        else {
            chunk.push_back(*iter);
            if(*iter == '}') {
                if(iter + 1 != pat.end() && *(iter + 1) == '}') {
                    ++iter;                 // skip second "}"
                }
                else {
                    throw std::logic_error("'}' should be escaped by another '}'");
                }
            }
        }
    }

    chunks.push_back(chunk);
    chunk.clear();
}

template <typename Char>
template <int N>
basic_pattern<Char>::basic_pattern(const Char(&pat)[N])
    : basic_pattern(std::basic_string<Char>(pat))
{}


template <typename Char>
template <typename ... Types>
std::basic_string<Char> basic_pattern<Char>::format(Types ... args) const {
    if(chunks.size() != sizeof...(args) + 1) {
        throw std::logic_error("Wrong argument count");
    }
    return _format(args...);
}

template <typename Char>
template <typename Type, typename ... Types>
std::basic_string<Char> basic_pattern<Char>::_format(Type arg, Types ... args) const {
    std::basic_string<Char> result;
    size_t index = chunks.size() - sizeof...(args) - 2;
    result += chunks[index];
    result += fmt::format<Char>(arg);
    result += _format(args...);
    return result;
}


template <typename Char>
std::basic_string<Char> basic_pattern<Char>::_format() const {
    return chunks.back();
}

} // namespace fmt

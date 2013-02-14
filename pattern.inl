#include "format.hpp"

#include <iostream>


namespace fmt {

template <typename Char>
Pattern<Char>::Pattern(const std::basic_string<Char>& pat)
                /*: m_pat(pat)*/ {

    std::string chunk;
    for(auto iter = pat.begin(); iter != pat.end(); ++iter) {
        if(*iter == '{') {
            if(iter + 1 != pat.end() && *(iter + 1) == '{') {
                // shadow
            }
            else {
                for (; iter != pat.end() && *iter != '}'; ++iter) {}
                if (iter == pat.end()) {
                    // error: no matching }
                }
                else {
                    chunks.push_back(chunk);
                    chunk.clear();
                }
            }
        }
        else {
            chunk.push_back(*iter);
        }
    }

    chunks.push_back(chunk);
    chunk.clear();

    // for (auto& chunk : chunks) {
    //     std::cout << chunk << "/" << std::endl;
    // }
}


template <typename Char>
Pattern<Char>::Pattern(const char* pat)
    : Pattern(std::string(pat)) {
}


template <typename Char>
template <typename ... Types>
std::basic_string<Char> Pattern<Char>::format(Types ... args) {
    return _format(args...);
}

template <typename Char>
template <typename Type, typename ... Types>
std::basic_string<Char> Pattern<Char>::_format(Type arg, Types ... args) {
    std::basic_string<Char> result;
    size_t index = chunks.size() - sizeof...(args) - 2;
    result += chunks[index];
    result += fmt::format<Char>(arg);
    result += _format(args...);
    return result;
}


template <typename Char>
std::basic_string<Char> Pattern<Char>::_format() {
    return chunks.back();
}

} // namespace fmt

#ifndef DULCIFICUM_INCLUDE_DULCIFICUM_GCODE_AST_ENTRY_H
#define DULCIFICUM_INCLUDE_DULCIFICUM_GCODE_AST_ENTRY_H

#include "dulcificum/utils/char_range_literal.h"

#include <cstddef>
#include <ctre.hpp>
#include <string>

namespace dulcificum::gcode::ast
{

template<dulcificum::utils::CharRangeLiteral Pattern>
class Entry
{
public:
    Entry() = delete;
    Entry(size_t index, std::string line)
        : index{ index }
        , line{ std::move(line) } {};

    size_t index;
    std::string line;

    constexpr auto get()
    {
        return ctre::match<Pattern.value>(line);
    }
};

} // namespace dulcificum::gcode::ast

#endif // DULCIFICUM_INCLUDE_DULCIFICUM_GCODE_AST_ENTRY_H

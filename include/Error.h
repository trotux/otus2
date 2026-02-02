#pragma once

#include <system_error>

namespace otus
{

enum class MoveErrc
{
    Ok = 0,
    NoLocation = 1,
    NoVelocity,
    NoMovable,
    NoDirection,
    NoAngularVelocity,
    NoRotatable
};

std::error_code make_error_code(MoveErrc);

}  // namespace otus

namespace std
{
template<>
struct is_error_code_enum<otus::MoveErrc> : true_type
{};

}  // namespace std


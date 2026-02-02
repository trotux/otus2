#include "Error.h"

#include <string>
#include <system_error>

namespace otus
{

namespace
{

struct MoveErrcCategory : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int ev) const override;
};

const char* MoveErrcCategory::name() const noexcept
{
    return "movement";
}

std::string MoveErrcCategory::message(int ev) const
{
    switch (static_cast<MoveErrc>(ev))
    {
        case MoveErrc::NoLocation:
            return "non-existent object location";

        case MoveErrc::NoVelocity:
            return "non-existent object velocity";

        case MoveErrc::NoMovable:
            return "non-movable object";

        default:
            return "(unrecognized error)";
    }
}

const MoveErrcCategory theMoveErrcCategory{};

}  // anonymous namespace


std::error_code make_error_code(MoveErrc e)
{
    return {static_cast<int>(e), theMoveErrcCategory};
}

}  // namespace otus

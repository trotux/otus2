#pragma once

#include "Error.h"
#include "IMovableObject.h"
#include "Point.h"
#include <memory>
#include <system_error>

namespace otus
{

class Movement
{
public:
    Movement(IMovableObject& adapter)
        : m_adapter{adapter}
    {}

    std::error_code execute()
    {
        auto currentPosition = m_adapter.getPosition();
        auto currentVelocity = m_adapter.getVelocity();

        if (currentPosition == nullptr)
        {
            return MoveErrc::NoLocation;
        }

        if (currentVelocity == nullptr)
        {
            return MoveErrc::NoVelocity;
        }

        if (currentVelocity->getDeltaX() == 0 && currentVelocity->getDeltaY() == 0)
        {
            return MoveErrc::NoMovable;
        }

        auto newPosition = std::make_shared<Point>(
                currentPosition->getX() + currentVelocity->getDeltaX(),
                currentPosition->getY() + currentVelocity->getDeltaY());

        m_adapter.setPosition(newPosition);

        return MoveErrc::Ok;
    }

private:
    IMovableObject& m_adapter;
};

}

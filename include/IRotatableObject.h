#pragma once

#include "Direction.h"
#include "AngularVelocity.h"

#include <memory>

namespace otus
{

class IRotatableObject
{
public:
    virtual ~IRotatableObject() = default;
    virtual std::shared_ptr<Direction> getDirection() = 0;
    virtual void setDirection(std::shared_ptr<Direction>) = 0;
    virtual std::shared_ptr<AngularVelocity> getAngularVelocity() = 0;
};

}

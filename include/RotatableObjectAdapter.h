#pragma once

#include "AngularVelocity.h"
#include "Direction.h"
#include "IRotatableObject.h"
#include "UObject.h"

#include <memory>
#include <stdexcept>

namespace otus
{

class RotatableObjectAdapter : public IRotatableObject
{
public:
    RotatableObjectAdapter() = delete;
    RotatableObjectAdapter(std::shared_ptr<UObject> object)
        : m_object{object}
    {
        if (m_object == nullptr)
        {
            throw std::runtime_error("IMovableObject must be not nullptr");
        }
    }

    std::shared_ptr<Direction> getDirection() override
    {
        if (m_object == nullptr)
        {
            return nullptr;
        }

        return m_object->getProperty<Direction>("direction");
    }

    void setDirection(std::shared_ptr<Direction> direction) override
    {
        if (m_object != nullptr)
        {
            m_object->setProperty<Direction>("direction", direction);
        }
    }

    std::shared_ptr<AngularVelocity> getAngularVelocity() override
    {
        if (m_object == nullptr)
        {
            return nullptr;
        }

        return m_object->getProperty<AngularVelocity>("angular_velocity");
    }

private:
    std::shared_ptr<UObject> m_object;
};

}

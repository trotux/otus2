#pragma once

#include <cstdint>
#include "IProperty.h"

namespace otus
{

class Direction : public IProperty
{
public:
    Direction() = default;
    Direction(unsigned value)
        : m_value{value}
    {
        if (m_value >= rotateStepMax)
        {
            m_value = m_value % rotateStepMax;
        }
    }

    std::string name() override { return "direction"; }

    int getValue() { return m_value; }

private:
    static constexpr unsigned rotateStepMax = 120;
    unsigned m_value{0};
};

}  // namespace otus

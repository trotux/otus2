
#include "AngularVelocity.h"
#include "Error.h"
#include "RotatableObjectAdapter.h"
#include "UObject.h"
#include "Direction.h"
#include "Rotation.h"

#include <gtest/gtest.h>

#include <memory>
#include <string>

TEST(MoveObject, Rotation)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("direction", std::make_shared<otus::Direction>(0));
    object->setProperty("angular_velocity", std::make_shared<otus::AngularVelocity>(3));

    otus::RotatableObjectAdapter rotateAdapter(object);
    otus::Rotation rotation(rotateAdapter);

    auto err = rotation.execute();
    EXPECT_EQ(err, otus::MoveErrc::Ok);

    auto direction = object->getProperty<otus::Direction>("direction");
    ASSERT_NE(direction, nullptr);

    EXPECT_EQ(direction->getValue(), 3);
}

TEST(MoveObject, NoDirection)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("angular_velocity", std::make_shared<otus::AngularVelocity>(3));

    otus::RotatableObjectAdapter rotateAdapter(object);
    otus::Rotation rotation(rotateAdapter);

    auto err = rotation.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoDirection);
}

TEST(MoveObject, NoAngularVelocity)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("direction", std::make_shared<otus::Direction>(0));

    otus::RotatableObjectAdapter rotateAdapter(object);
    otus::Rotation rotation(rotateAdapter);

    auto err = rotation.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoAngularVelocity);
}

TEST(MoveObject, NoRotatable)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("direction", std::make_shared<otus::Direction>(0));
    object->setProperty("angular_velocity", std::make_shared<otus::AngularVelocity>(0));

    otus::RotatableObjectAdapter rotateAdapter(object);
    otus::Rotation rotation(rotateAdapter);

    auto err = rotation.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoRotatable);
}

#include "Error.h"
#include "MovableObjectAdapter.h"
#include "UObject.h"
#include "Point.h"
#include "Velocity.h"
#include "Movement.h"

#include <gtest/gtest.h>

#include <memory>
#include <string>

TEST(MoveObject, LinearMoving)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("position", std::make_shared<otus::Point>(12,5));
    object->setProperty("velocity", std::make_shared<otus::Velocity>(-7,3));

    otus::MovableObjectAdapter moveAdapter(object);
    otus::Movement movement(moveAdapter);

    auto err = movement.execute();
    EXPECT_EQ(err, otus::MoveErrc::Ok);

    auto position = object->getProperty<otus::Point>("position");

    EXPECT_EQ(position->getX(), 5);
    EXPECT_EQ(position->getY(), 8);
}

TEST(MoveObject, NoPosition)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("velocity", std::make_shared<otus::Velocity>(-7,3));

    otus::MovableObjectAdapter moveAdapter(object);
    otus::Movement movement(moveAdapter);

    auto err = movement.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoLocation);
}

TEST(MoveObject, NoVelocity)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("position", std::make_shared<otus::Point>(12,5));

    otus::MovableObjectAdapter moveAdapter(object);
    otus::Movement movement(moveAdapter);

    auto err = movement.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoVelocity);
}

TEST(MoveObject, NoMovable)
{
    auto object = std::make_shared<otus::UObject>();

    EXPECT_NE(object, nullptr);

    object->setProperty("position", std::make_shared<otus::Point>(12,5));
    object->setProperty("velocity", std::make_shared<otus::Velocity>());

    otus::MovableObjectAdapter moveAdapter(object);
    otus::Movement movement(moveAdapter);

    auto err = movement.execute();
    EXPECT_EQ(err, otus::MoveErrc::NoMovable);
}

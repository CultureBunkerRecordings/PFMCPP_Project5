#pragma once
#include "LeakedObjectDetector.h"

#include "Animal.h"
#include "Car.h"
#include "Multiply.h"

struct YourLife
{
    YourLife();
    ~YourLife();

    Animal pet;
    Car ford;
    Multiply homeWork;
    JUCE_LEAK_DETECTOR(YourLife)
};

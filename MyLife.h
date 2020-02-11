#pragma once
#include "Animal.h"
#include "Car.h"
#include "Multiply.h"

struct MyLife
{
    MyLife();
    ~MyLife();

    Animal pet;
    Car ford;
    Multiply homeWork;
    JUCE_LEAK_DETECTOR(MyLife)
};

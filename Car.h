#pragma once
#include "LeakedObjectDetector.h"


struct Car
{
    Car();
    ~Car();
    void distanceTraveled();
    void setDriving(bool d);
    void setPetrol(float p);
    void printMiles();

    bool driving;
    float petrol;
    int miles;
    JUCE_LEAK_DETECTOR(Car)
};
#pragma once
#include "LeakedObjectDetector.h"


struct Multiply
{
    Multiply();
    ~Multiply();
    void multipleOf(int num);
    void setMaxMultiple(int mM);
    void printFinalResult();

    int maxMultiple;
    int result;
    JUCE_LEAK_DETECTOR(Multiply)
};

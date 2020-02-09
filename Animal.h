
#pragma once
#include "LeakedObjectDetector.h"

struct Animal
{
    Animal();
    ~Animal();
    void howManyToes();
    void setNumLegs(int nL);
    void setNumToesOnFoot(int nTOF);
    void printNumLegs();

    int totalToes;
    int numLegs; 
    int numToesOnFoot;
    bool isItAPobble = false;
    JUCE_LEAK_DETECTOR(Animal)
};

#include <iostream>
#include "Animal.h"
#include "Wrapper.h"

Animal::Animal() : totalToes(0), numLegs(0), numToesOnFoot(0), isItAPobble(false)
{

}

Animal::~Animal()
{
    std::cout << "Destroy Animal" << std::endl;
    // std::cout << std::endl;

}

void Animal::howManyToes()
{
    std::cout << std::endl;
    for(int i = 1; i<=numLegs;i++)
    {
        totalToes = i*numToesOnFoot;
        std::cout << "foot: " << i << " Toe count: " << totalToes << std::endl;
    }

    if(totalToes==0)
    {
        std::cout << "The pobble who had no Toes!" << std::endl;
        // std::cout << std::endl;

        isItAPobble = true;
    }
    std::cout << std::endl;

}

void Animal::setNumLegs(int nL)
{
    numLegs = nL;
}

void Animal::setNumToesOnFoot(int nTOF)
{
    numToesOnFoot = nTOF; 
}

void Animal::printNumLegs()
{
    std::cout << "this-> animal has: " << numLegs << "legs" << std::endl;
    // std::cout << std::endl;
}
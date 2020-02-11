#include <iostream>
#include "MyLife.h"
#include "Wrapper.h"


MyLife::MyLife()
{

}

MyLife::~MyLife()
{
    std::cout << "This is called from the destructor" << std::endl;
    pet.howManyToes();
}

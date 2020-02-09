#include <iostream>
#include "YourLife.h"
#include "Wrapper.h"

YourLife::YourLife()
{

}

YourLife::~YourLife()
{
    pet.setNumLegs(4);
    pet.setNumToesOnFoot(5);
    std::cout << "This is called from the destructor" << std::endl;
    pet.howManyToes();
}


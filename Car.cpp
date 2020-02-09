#include <iostream>
#include "Car.h"
#include "Wrapper.h"

Car::Car() : driving(false), petrol(8.0f), miles(0)
{

}

Car::~Car()
{
    std::cout << "Destroy Car" << std::endl;
    // std::cout << std::endl;
}

void Car::distanceTraveled()
{
    while (driving)
    {
        std::cout << "miles travelled: " << miles << " petrol left: " << petrol << std::endl;
        miles++;
        petrol -= 0.5f;
        if(petrol <= 0.0f)
        {
            std::cout << "out of petrol" << std::endl;
            // std::cout << std::endl;
            break;
        }
    }

}

void Car::setDriving(bool d)
{
    driving = d;
}

void Car::setPetrol(float p)
{
    petrol = p;
}

void Car::printMiles()
{
    std::cout << "this-> car has traveled " << this->miles << " miles" << std::endl;
    // std::cout << std::endl;
}
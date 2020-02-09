#include <iostream>
#include "Multiply.h"
#include "Wrapper.h"


Multiply::Multiply() : maxMultiple(12), result(0) 
{

}

Multiply::~Multiply()
{
    std::cout << "Destroy Multiply" << std::endl;
    // std::cout << std::endl;
}

void Multiply::multipleOf(int num)
{
    for(int i = 0; i<=maxMultiple;i++)
    {
    result = i * num; 
    std::cout << num << " times " << i << " equals " << result << std::endl; 
    }
    // std::cout << std::endl;
}

void Multiply::setMaxMultiple(int mM)
{
    maxMultiple = mM;
}

void Multiply::printFinalResult()
{
    std::cout << "this-> final result is " << this->result << std::endl;
    // std::cout << std::endl;

}
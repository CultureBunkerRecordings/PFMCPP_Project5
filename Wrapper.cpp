#include "Wrapper.h"
#include "Multiply.h"
#include "Car.h"
#include "Animal.h"
#include "MyLife.h"
#include "YourLife.h"

AnimalWrapper::AnimalWrapper(Animal* p):pAnimal(p)
{

}

AnimalWrapper::~AnimalWrapper()
{ 
    delete pAnimal;
}

CarWrapper::CarWrapper(Car* p): pCar(p) 
{

}

CarWrapper::~CarWrapper()
{
    delete pCar; 
}

MultiplyWrapper::MultiplyWrapper(Multiply* p): pMultiply(p) 
{

}

MultiplyWrapper::~MultiplyWrapper() 
{
    delete pMultiply;
}

MyLifeWrapper::MyLifeWrapper(MyLife* p): pMyLife(p) 
{

}

MyLifeWrapper::~MyLifeWrapper() 
{
    delete pMyLife;
}

//////////////////////////////////////////////

YourLifeWrapper::YourLifeWrapper(YourLife* p): pYourLife(p) 
{

}

YourLifeWrapper::~YourLifeWrapper()
{
    delete pYourLife;
}

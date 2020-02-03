/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */

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

struct AnimalWrapper
{
    AnimalWrapper(Animal* p):pAnimal(p){}
    ~AnimalWrapper(){ delete pAnimal; }
    Animal* pAnimal = nullptr;
};

/*
 copied UDT 2:
 */

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

struct CarWrapper
{
    CarWrapper(Car* p): pCar(p) {}
    ~CarWrapper(){ delete pCar; }
    Car* pCar = nullptr;
};


/*
 copied UDT 3:
 */

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

struct MultiplyWrapper
{
    MultiplyWrapper(Multiply* p): pMultiply(p) {}
    ~MultiplyWrapper() { delete pMultiply; }
    Multiply* pMultiply = nullptr;
};
/*
 new UDT 4:
 */

struct MyLife
{
    MyLife();
    ~MyLife();

    Animal pet;
    Car ford;
    Multiply homeWork;
    JUCE_LEAK_DETECTOR(MyLife)
};

struct MyLifeWrapper
{
    MyLifeWrapper(MyLife* p): pMyLife(p) {}
    ~MyLifeWrapper() { delete pMyLife; }
    MyLife* pMyLife = nullptr;
};

/*
 new UDT 5:
 */

struct YourLife
{
    YourLife();
    ~YourLife();

    Animal pet;
    Car ford;
    Multiply homeWork;
    JUCE_LEAK_DETECTOR(YourLife)
};

struct YourLifeWrapper
{
    YourLifeWrapper(YourLife* p): pYourLife(p) {}
    ~YourLifeWrapper() { delete pYourLife; }
    YourLife* pYourLife = nullptr;
};

///////////////////////////////////////////////////////////
Animal::Animal() : totalToes(0), numLegs(0), numToesOnFoot(0), isItAPobble(false)
{

}

Animal::~Animal()
{
    std::cout << "Destroy Animal" << std::endl;
    std::cout << std::endl;

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
        std::cout << std::endl;

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
    std::cout << std::endl;
}
///////////////////////////////////////////////////////////

Car::Car() : driving(false), petrol(8.0f), miles(0)
{

}

Car::~Car()
{
    std::cout << "Destroy Car" << std::endl;
    std::cout << std::endl;
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
            std::cout << std::endl;
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
    std::cout << std::endl;
}

///////////////////////////////////////////////////////////

Multiply::Multiply() : maxMultiple(12), result(0) 
{

}

Multiply::~Multiply()
{
    std::cout << "Destroy Multiply" << std::endl;
    std::cout << std::endl;
}

void Multiply::multipleOf(int num)
{
    for(int i = 0; i<=maxMultiple;i++)
    {
    result = num * i;
    std::cout<< num << " times " << i << " equals " << result << std::endl; 
    }
    std::cout << std::endl;
}

void Multiply::setMaxMultiple(int mM)
{
    maxMultiple = mM;
}

void Multiply::printFinalResult()
{
    std::cout << "this-> final result is " << this->result << std::endl;
    std::cout << std::endl;

}

///////////////////////////////////////////////////////////

MyLife::MyLife()
{

}

MyLife::~MyLife()
{
    std::cout << "This is called from the destructor" << std::endl;
    pet.howManyToes();
}

///////////////////////////////////////////////////////////

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


int main()
{
    Animal a;
    a.setNumLegs(8);
    a.setNumToesOnFoot(4);
    a.howManyToes();

    AnimalWrapper aW(new Animal());

    std::cout << "This animal has: " << a.numLegs << " legs" << std::endl;
    a.printNumLegs();

    std::cout << "This heap animal has: " << aW.pAnimal->numLegs << " legs" << std::endl;
    aW.pAnimal->printNumLegs();

    Car c;
    c.setPetrol(10.5f);
    c.setDriving(true);
    c.distanceTraveled();

    CarWrapper cW(new Car());

    std::cout << "This car has traveled " << c.miles << " miles" << std::endl;
    c.printMiles();

    std::cout << "This heap car has traveled " << cW.pCar->miles << " miles" << std::endl;
    cW.pCar->printMiles();

    Multiply m;
    m.setMaxMultiple(20);
    m.multipleOf(8);

    MultiplyWrapper mW(new Multiply());

    std::cout << "The Final result from my times table is  " << m.result << std::endl;
    m.printFinalResult();

    std::cout << "The Final heap result from my times table is  " << mW.pMultiply->result << std::endl;
    mW.pMultiply->printFinalResult();

    MyLife me;
    YourLife you;
}

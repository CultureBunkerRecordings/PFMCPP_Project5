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
};


///////////////////////////////////////////////////////////
Animal::Animal() : totalToes(0), numLegs(0), numToesOnFoot(0), isItAPobble(false)
{

}

Animal::~Animal()
{
    std::cout << "Destroy Animal" << std::endl;
}

void Animal::howManyToes()
{
    for(int i = 1; i<=numLegs;i++)
    {
        totalToes = i*numToesOnFoot;
        std::cout << "foot: " << i << " Toe count: " << totalToes << std::endl; 
    }

    if(totalToes==0)
    {
        std::cout << "The pobble who had no Toes!" << std::endl;
        isItAPobble = true;
    }
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
}
///////////////////////////////////////////////////////////

Car::Car() : driving(false), petrol(8.0f), miles(0)
{

}

Car::~Car()
{
    std::cout << "Destroy Car" << std::endl;
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
}

///////////////////////////////////////////////////////////

Multiply::Multiply() : maxMultiple(12), result(0) 
{

}

Multiply::~Multiply()
{
    std::cout << "Destroy Multiply" << std::endl;
}

void Multiply::multipleOf(int num)
{
    for(int i = 0; i<=maxMultiple;i++)
    {
    result = num * i;
    std::cout<< num << " times " << i << " equals " << result << std::endl; 
    }

}

void Multiply::setMaxMultiple(int mM)
{
    maxMultiple = mM;
}

void Multiply::printFinalResult()
{
    std::cout << "this-> final result is " << this->result << std::endl;

}

///////////////////////////////////////////////////////////

MyLife::MyLife()
{

}

MyLife::~MyLife()
{
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
    pet.howManyToes();
}


int main()
{
    Animal a;
    a.setNumLegs(8);
    a.setNumToesOnFoot(4);
    a.howManyToes();

    std::cout << "This animal has: " << a.numLegs << " legs" << std::endl;
    a.printNumLegs();

    Car c;
    c.setPetrol(10.5f);
    c.setDriving(true);
    c.distanceTraveled();

    std::cout << "This car has traveled " << c.miles << " miles" << std::endl;
    c.printMiles();

    Multiply m;
    m.setMaxMultiple(20);
    m.multipleOf(8);

    std::cout << "The Final result from my times table is  " << m.result << std::endl;
    m.printFinalResult();

    MyLife me;
    YourLife you;
}

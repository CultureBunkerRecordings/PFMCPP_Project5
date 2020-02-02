/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}


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

private:
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

private:
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

private:
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
private:
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
private:
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
	Example::main();
    Animal a;
    a.setNumLegs(8);
    a.setNumToesOnFoot(4);
    a.howManyToes();

    Car c;
    c.setPetrol(10.5f);
    c.setDriving(true);
    c.distanceTraveled();
    std::cout << "good to go!" << std::endl;

    Multiply m;
    m.setMaxMultiple(20);
    m.multipleOf(8);

    MyLife me;
    YourLife you;
}

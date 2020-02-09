/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Animal.h"
#include "Car.h"
#include "Multiply.h"
#include "MyLife.h"
#include "YourLife.h"
#include "Wrapper.h"

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
    std::cout << "good to go" << std::endl;
    return 0;
}

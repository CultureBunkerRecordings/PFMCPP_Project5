
struct Animal;
struct Car;
struct Multiply;
struct MyLife;
struct YourLife;

struct AnimalWrapper
{
    AnimalWrapper(Animal* p);
    ~AnimalWrapper();
    Animal* pAnimal = nullptr;
};

struct CarWrapper
{
    CarWrapper(Car* p);
    ~CarWrapper();
    Car* pCar = nullptr;
};

struct MultiplyWrapper
{
    MultiplyWrapper(Multiply* p);
    ~MultiplyWrapper();
    Multiply* pMultiply = nullptr;
};

struct MyLifeWrapper
{
    MyLifeWrapper(MyLife* p);
    ~MyLifeWrapper();
    MyLife* pMyLife = nullptr;
};

struct YourLifeWrapper
{
    YourLifeWrapper(YourLife* p);
    ~YourLifeWrapper();
    YourLife* pYourLife = nullptr;
}; 

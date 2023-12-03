#include <iostream>
#include <string>

class SubsystemA 
{
public:
    void operationA() const 
    {
        std::cout << "Подсистема А: Операция А" << std::endl;
    }
};


class SubsystemB 
{
public:
    void operationB() const 
    {
        std::cout << "Подсистема В: Операция В" << std::endl;
    }
};


class SubsystemC
{
public:
    void operationC() const 
    {
        std::cout << "Подсистема С: Операция С" << std::endl;
    }
};


class Facade 
{
public:
    Facade() : subsystemA(), subsystemB(), subsystemC() {}


    void operation() const 
    {
        std::cout << "Фасад: Операции" << std::endl;
        subsystemA.operationA();
        subsystemB.operationB();
        subsystemC.operationC();
    }

private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
    SubsystemC subsystemC;
};

int main() 
{

    setlocale(LC_ALL, "ru");


    Facade facade;
    facade.operation();

    return 0;
}
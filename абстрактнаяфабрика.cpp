#include <iostream>
#include <string>

class AbstractProductA 
{
public:
    virtual std::string getName() const = 0;
};


class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string getName() const override 
    {
        return "Продукт А1";
    }
};


class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string getName() const override 
    {
        return "продукт А2";
    }
};


class AbstractProductB 
{
public:
    virtual std::string getName() const = 0;
};


class ConcreteProductB1 : public AbstractProductB 
{
public:
    std::string getName() const override
    {
        return "Продукт В1";
    }
};


class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string getName() const override
    {
        return "Продукт В2";
    }
};


class AbstractFactory 
{
public:
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};


class ConcreteFactory1 : public AbstractFactory 
{
public:
    AbstractProductA* createProductA() const override 
    {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() const override
    {
        return new ConcreteProductB1();
    }
};


class ConcreteFactory2 : public AbstractFactory 
{
public:
    AbstractProductA* createProductA() const override
    {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() const override
    {
        return new ConcreteProductB2();
    }
};

int main() 
{

    setlocale(LC_ALL, "ru");


    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    std::cout << "Продукт A: " << productA1->getName() << std::endl;
    std::cout << "Продукт B: " << productB1->getName() << std::endl;

    delete factory1;
    delete productA1;
    delete productB1;


    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    std::cout << "Продукт A: " << productA2->getName() << std::endl;
    std::cout << "продукт B: " << productB2->getName() << std::endl;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}
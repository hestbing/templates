#include <iostream>
#include <string>

class Implementor 
{
public:
    virtual void implementOperation() const = 0;
    virtual ~Implementor() = default;
};


class ConcreteImplementorA : public Implementor
{
public:
    void implementOperation() const override 
    {
        std::cout << "Конкретный исполнитель A: реализация операции" << std::endl;
    }
};


class ConcreteImplementorB : public Implementor 
{
public:
    void implementOperation() const override 
    {
        std::cout << "Конкретный исполнитель В: реализация операции" << std::endl;
    }
};


class Abstraction 
{
public:
    Abstraction(Implementor* implementor) : implementor_(implementor) {}

    virtual void performOperation() const
    {
        implementor_->implementOperation();
    }

    virtual ~Abstraction()
    {
        delete implementor_;
    }

private:
    Implementor* implementor_;
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor* implementor) : Abstraction(implementor) {}

    void performExtendedOperation() const 
    {
        std::cout << "Усовершенствованная абстракция: выполнение расширенной операции" << std::endl;
    }
};

int main()
{
    
    setlocale(LC_ALL, "ru");


    Implementor* implementorA = new ConcreteImplementorA;
    Abstraction abstractionA(implementorA);
    abstractionA.performOperation();

    Implementor* implementorB = new ConcreteImplementorB;
    Abstraction abstractionB(implementorB);
    abstractionB.performOperation();

    RefinedAbstraction refinedAbstractionA(implementorA);
    refinedAbstractionA.performOperation();
    refinedAbstractionA.performExtendedOperation();

    delete implementorA;
    delete implementorB;

    return 0;
}
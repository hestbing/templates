#include <iostream>


class AbstractClass
{
public:

    void templateMethod() 
    {
        stepOne();
        stepTwo();
        if (hook()) 
        {
            stepThree();
        }
        stepFour();
    }

    virtual ~AbstractClass() = default;

protected:

    virtual void stepOne() const 
    {
        std::cout << "Абстрактный класс: шаг первый" << std::endl;
    }

    virtual void stepTwo() const 
    {
        std::cout << "Абстрактный класс: шаг второй" << std::endl;
    }

    virtual void stepThree() const
    {
        std::cout << "Абстрактный класс: шаг третий" << std::endl;
    }

    virtual void stepFour() const 
    {
        std::cout << "Абстрактный класс: шаг четвертый" << std::endl;
    }

    virtual bool hook() const
    {
        return true;
    }
};


class ConcreteClass : public AbstractClass
{
protected:
    void stepOne() const override
    {
        std::cout << "Конкретный класс: переопределение первого шага" << std::endl;
    }

    void stepThree() const override 
    {
        std::cout << "Конкретный класс: переопределение второго шага" << std::endl;
    }

    bool hook() const override 
    {
        std::cout << "Конкретный класс: переопределение третьего шага" << std::endl;
        return false;
    }
};

int main() 
{

    setlocale(LC_ALL, "ru");


    ConcreteClass concreteObject;
    concreteObject.templateMethod();

    return 0;
}
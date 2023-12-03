#include <iostream>
#include <string>


class Component 
{
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};


class ConcreteComponent : public Component 
{
public:
    void operation() const override 
    {
        std::cout << "Конкретный компонент: Операция" << std::endl;
    }
};


class Decorator : public Component 
{
public:
    Decorator(Component* component) : component_(component) {}

    void operation() const override 
    {
        if (component_)
        {
            component_->operation();
        }
    }

    virtual ~Decorator() 
    {
        delete component_;
    }

private:
    Component* component_;
};


class ConcreteDecoratorA : public Decorator 
{
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    void operation() const override 
    {
        Decorator::operation();
        addedBehavior();
    }

private:
    void addedBehavior() const
    {
        std::cout << "Конкретный декоратор А: добавлено поведение" << std::endl;
    }
};


class ConcreteDecoratorB : public Decorator 
{
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    void operation() const override
    {
        Decorator::operation();
        addedBehavior();
    }

private:
    void addedBehavior() const 
    {
        std::cout << "Конкретный декоратор В: добавлено поведение" << std::endl;
    }
};

int main()
{

    setlocale(LC_ALL, "ru");


    ConcreteComponent concreteComponent;

    ConcreteDecoratorA decoratorA(&concreteComponent);

    ConcreteDecoratorB decoratorB(&decoratorA);

    decoratorB.operation();

    return 0;
}
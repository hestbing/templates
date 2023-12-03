#include <iostream>
#include <vector>

class ConcreteComponentA;
class ConcreteComponentB;


class Visitor 
{
public:
    virtual void visitConcreteComponentA(const ConcreteComponentA& element) const = 0;
    virtual void visitConcreteComponentB(const ConcreteComponentB& element) const = 0;
    virtual ~Visitor() = default;
};


class Component 
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Component() = default;
};


class ConcreteComponentA : public Component 
{
public:
    void accept(Visitor& visitor) override 
    {
        visitor.visitConcreteComponentA(*this);
    }

    std::string operationA() const
    {
        return "конкретный компонент А";
    }
};


class ConcreteComponentB : public Component
{
public:
    void accept(Visitor& visitor) override 
    {
        visitor.visitConcreteComponentB(*this);
    }

    std::string operationB() const
    {
        return "Конкретный компонент B";
    }
};


class ConcreteVisitor : public Visitor 
{
public:
    void visitConcreteComponentA(const ConcreteComponentA& element) const override
    {
        std::cout << "Посещения посетителей " << element.operationA() << std::endl;
    }

    void visitConcreteComponentB(const ConcreteComponentB& element) const override 
    {
        std::cout << "Посещения посетителей " << element.operationB() << std::endl;
    }
};


int main() 
{

    setlocale(LC_ALL, "ru");


    std::vector<Component*> components = { new ConcreteComponentA(), new ConcreteComponentB() };
    ConcreteVisitor visitor;

    for (const auto& component : components)
    {
        component->accept(visitor);
    }

    for (const auto& component : components)
    {
        delete component;
    }

    return 0;
}
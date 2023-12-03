#include <iostream>
#include <string>
#include <vector>

class Component 
{
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};


class Leaf : public Component
{
public:
    void operation() const override
    {
        std::cout << "Лист: Операция" << std::endl;
    }
};


class Composite : public Component
{
public:
    void addComponent(Component* component) 
    {
        components.push_back(component);
    }

    void operation() const override 
    {
        std::cout << "Композитный: Операция" << std::endl;
        for (const auto& component : components) 
        {
            component->operation();
        }
    }

private:
    std::vector<Component*> components;
};

int main()
{
   
    setlocale(LC_ALL, "ru");


    Leaf leaf1;
    Leaf leaf2;

    Composite composite;
    composite.addComponent(&leaf1);
    composite.addComponent(&leaf2);

    leaf1.operation();
    std::cout << std::endl;

    leaf2.operation();
    std::cout << std::endl;

    composite.operation();

    return 0;
}
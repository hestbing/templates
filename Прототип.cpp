#include <iostream>
#include <string>

class Prototype 
{
public:
    virtual Prototype* clone() const = 0;
    virtual void showInfo() const = 0;
};


class ConcretePrototype : public Prototype 
{
public:
    ConcretePrototype(int id, std::string data) : id_(id), data_(data) {}

    Prototype* clone() const override
    {
        return new ConcretePrototype(*this);
    }

    void showInfo() const override
    {
        std::cout << "Конкретный прототип: " << "ID=" << id_ << ", Data=" << data_ << std::endl;
    }

private:
    int id_;
    std::string data_;
};

int main() 
{
   
    setlocale(LC_ALL, "ru");


    ConcretePrototype prototype1(1, "Data 1");

    Prototype* clonedPrototype = prototype1.clone();

    clonedPrototype->showInfo();

    delete clonedPrototype;

    return 0;
}
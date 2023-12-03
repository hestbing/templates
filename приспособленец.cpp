#include <iostream>
#include <string>
#include <unordered_map>


class Flyweight 
{
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
    virtual ~Flyweight() = default;
};


class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState_(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override
    {
        std::cout << "Конкретный приспособленец: Внутреннее состояние - " << intrinsicState_
            << ", Внешнее состояние - " << extrinsicState << std::endl;
    }

private:
    std::string intrinsicState_;
};

class FlyweightFactory 
{
public:
    Flyweight* getFlyweight(const std::string& key) 
    {
        if (flyweights.find(key) == flyweights.end()) 
        {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() 
    {
        for (auto& pair : flyweights) 
        {
            delete pair.second;
        }
    }

private:
    std::unordered_map<std::string, Flyweight*> flyweights;
};

int main() 
{

    setlocale(LC_ALL, "ru");


    FlyweightFactory flyweightFactory;

    Flyweight* flyweight1 = flyweightFactory.getFlyweight("общий");
    flyweight1->operation("состояние 1");

    Flyweight* flyweight2 = flyweightFactory.getFlyweight("общий");
    flyweight2->operation("состояние 2");

    Flyweight* flyweight3 = flyweightFactory.getFlyweight("уникальный");
    flyweight3->operation("состояние 3");

    return 0;
}
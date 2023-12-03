#include <iostream>
#include <string>


class Target  
{
public:
    virtual void request() const = 0;
    virtual ~Target() = default;
};

class Adaptee 
{
public:
    void specificRequest() const 
    {
        std::cout << "Адаптируемый: Особый запрос" << std::endl;
    }
};


class Adapter : public Target 
{
public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}

    void request() const override 
    {
        adaptee_->specificRequest();
    }

private:
    Adaptee* adaptee_;
};


class Client
{
public:
    Client(Target* target) : target_(target) {}

    void executeRequest() const 
    {
        target_->request();
    }

private:
    Target* target_;
};


class ConcreteAdapter : public Target 
{
public:
    void request() const override 
    {
        std::cout << "Конкретный адаптер: обработка запроса" << std::endl;
    }
};

int main()
{
    
    setlocale(LC_ALL, "ru");


    Adaptee adaptee;
    Adapter adapter(&adaptee);

    Client client(&adapter);
    client.executeRequest();

    ConcreteAdapter concreteAdapter;
    client = Client(&concreteAdapter);
    client.executeRequest();

    return 0;
}
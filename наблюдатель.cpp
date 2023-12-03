#include <iostream>
#include <vector>
#include <string>


class Observer 
{
public:
    virtual void update(const std::string& message) = 0;
};


class ConcreteObserver : public Observer 
{
public:
    ConcreteObserver(const std::string& name) : name_(name) {}

    void update(const std::string& message) override
    {
        std::cout << name_ << " получил сообщение: " << message << std::endl;
    }

private:
    std::string name_;
};


class Subject 
{
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};


class ConcreteSubject : public Subject 
{
public:
    void addObserver(Observer* observer) override 
    {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) override 
    {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end())
        {
            observers_.erase(it);
        }
    }

    void notifyObservers(const std::string& message) override
    {
        for (auto observer : observers_)
        {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> observers_;
};


int main() 
{
  
    setlocale(LC_ALL, "ru");


    ConcreteSubject subject;
    ConcreteObserver observer1("Наблядатель 1");
    ConcreteObserver observer2("Наблюдатель 2");
 
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    
    subject.notifyObservers("Привет наблюдатель");
    
    subject.removeObserver(&observer1);
    
    subject.notifyObservers("Остался один наблюдатель");

    return 0;
}
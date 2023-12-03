#include <iostream>
#include <string>


class Mediator
{
public:
    virtual void sendMessage(const class Colleague* sender, const std::string& message) const = 0;
};


class Colleague 
{
public:
    Colleague(Mediator* mediator, const std::string& name) : mediator_(mediator), name_(name) {}

    virtual void sendMessage(const std::string& message) const 
    {
        mediator_->sendMessage(this, message);
    }

    virtual void receiveMessage(const std::string& message) const
    {
        std::cout << name_ << " получено сообщение: " << message << std::endl;
    }

    virtual ~Colleague() = default;

private:
    Mediator* mediator_;
    std::string name_;
};


class ConcreteMediator : public Mediator
{
public:
    void setColleague1(Colleague* colleague)
    {
        colleague1_ = colleague;
    }

    void setColleague2(Colleague* colleague) 
    {
        colleague2_ = colleague;
    }

    void sendMessage(const Colleague* sender, const std::string& message) const override 
    {
        if (sender == colleague1_)
        {
            colleague2_->receiveMessage(message);
        }
        else if (sender == colleague2_) 
        {
            colleague1_->receiveMessage(message);
        }
    }

private:
    Colleague* colleague1_;
    Colleague* colleague2_;
};


class ConcreteColleague : public Colleague 
{
public:
    ConcreteColleague(Mediator* mediator, const std::string& name) : Colleague(mediator, name) {}

};

int main() 
{

    setlocale(LC_ALL, "ru");


    ConcreteMediator mediator;

    ConcreteColleague colleague1(&mediator, "Коллега 1");
    ConcreteColleague colleague2(&mediator, "коллега 2");


    mediator.setColleague1(&colleague1);
    mediator.setColleague2(&colleague2);

    colleague1.sendMessage("Привет от коллеги 1!");

    return 0;
}
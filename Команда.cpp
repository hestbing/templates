#include <iostream>

class Command 
{
public:
    virtual void execute() = 0;
};


class ConcreteCommandA : public Command 
{
public:
    void execute() override
    {
        std::cout << "Выполнение команды А" << std::endl;
    }
};


class ConcreteCommandB : public Command 
{
public:
    void execute() override 
    {
        std::cout << "Выполнение команды В" << std::endl;
    }
};


class Receiver 
{
public:
    void actionA() 
    {
        std::cout << "Получатель выполняет действие А" << std::endl;
    }

    void actionB() {
        std::cout << "Получатель выполняет действие В" << std::endl;
    }
};


class Invoker 
{
public:
    void setCommand(Command* command) 
    {
        command_ = command;
    }

    void executeCommand() 
    {
        if (command_) 
        {
            command_->execute();
        }
        else
        {
            std::cout << "Команда не выбрана" << std::endl;
        }
    }

private:
    Command* command_;
};

class Client
{
public:
    Client(Receiver* receiver) : receiver_(receiver) {}

    void executeCommand(Command* command) 
    {
        command->execute();
    }

    void executeActionA() 
    {
        receiver_->actionA();
    }

    void executeActionB() 
    {
        receiver_->actionB();
    }

private:
    Receiver* receiver_;
};


int main() 
{

    setlocale(LC_ALL, "ru");


    ConcreteCommandA commandA;
    ConcreteCommandB commandB;

    Receiver receiver;

    Client client(&receiver);

    Invoker invokerA;
    invokerA.setCommand(&commandA);
    invokerA.executeCommand();

    Invoker invokerB;
    invokerB.setCommand(&commandB);
    invokerB.executeCommand();

    client.executeActionA();
    client.executeActionB();

    return 0;
}
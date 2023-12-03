#include <iostream>


class State
{
public:
    virtual void handle() = 0;
};


class ConcreteStateA : public State 
{
public:
    void handle() override 
    {
        std::cout << "Обработка состояния А" << std::endl;
    }
};


class ConcreteStateB : public State 
{
public:
    void handle() override 
    {
        std::cout << "Обработка состояния В" << std::endl;
    }
};


class Context
{
public:
    Context(State* initialState) : state_(initialState) {}

    void setState(State* state) 
    {
        state_ = state;
    }

    void request()
    {
        state_->handle();
    }

private:
    State* state_;
};


int main()
{

    setlocale(LC_ALL, "ru");


    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context(&stateA);

    context.request();

    context.setState(&stateB);
    context.request();

    return 0;
}
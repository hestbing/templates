#include <iostream>

class Strategy 
{
public:
    virtual void execute() = 0;
};


class ConcreteStrategyA : public Strategy
{
public:
    void execute() override 
    {
        std::cout << "Реализация стратегии А" << std::endl;
    }
};


class ConcreteStrategyB : public Strategy 
{
public:
    void execute() override 
    {
        std::cout << "Реализация стратегии В" << std::endl;
    }
};


class Context 
{
public:
    Context(Strategy* strategy) : strategy_(strategy) {}

    void setStrategy(Strategy* strategy) 
    {
        strategy_ = strategy;
    }

    void executeStrategy() 
    {
        if (strategy_) 
        {
            strategy_->execute();
        }
        else
        {
            std::cout << "Стратегия не выбрана" << std::endl;
        }
    }

private:
    Strategy* strategy_;
};


int main() 
{
    setlocale(LC_ALL, "ru");



    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);

    context.executeStrategy();

    context.setStrategy(&strategyB);
    context.executeStrategy();

    return 0;
}
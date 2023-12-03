#include <iostream>
#include <string>


class Handler 
{
public:
    virtual void setNextHandler(Handler* nextHandler) = 0;
    virtual void handleRequest(const std::string& request) = 0;
};


class ConcreteHandlerA : public Handler 
{
public:
    void setNextHandler(Handler* nextHandler) override 
    {
        nextHandler_ = nextHandler;
    }

    void handleRequest(const std::string& request) override 
    {
        if (request == "A") 
        {
            std::cout << "Конкретный обработчик A обрабатывает запрос: " << request << std::endl;
        }
        else if (nextHandler_ != nullptr) 
        {
            nextHandler_->handleRequest(request);
        }
        else 
        {
            std::cout << "Ни один обработчик не может обработать запрос: " << request << std::endl;
        }
    }

private:
    Handler* nextHandler_;
};


class ConcreteHandlerB : public Handler 
{
public:
    void setNextHandler(Handler* nextHandler) override 
    {
        nextHandler_ = nextHandler;
    }

    void handleRequest(const std::string& request) override
    {
        if (request == "B") 
        {
            std::cout << "Конкретный обработчик B обрабатывает запрос: " << request << std::endl;
        }
        else if (nextHandler_ != nullptr)
        {
            nextHandler_->handleRequest(request);
        }
        else
        {
            std::cout << "Ни один обработчик не может обработать запрос: " << request << std::endl;
        }
    }

private:
    Handler* nextHandler_;
};


int main()
{
 
    setlocale(LC_ALL, "ru");


    Handler* handlerA = new ConcreteHandlerA();
    Handler* handlerB = new ConcreteHandlerB();

    handlerA->setNextHandler(handlerB);

    handlerA->handleRequest("A");
    handlerA->handleRequest("B");
    handlerA->handleRequest("C");


    delete handlerA;
    delete handlerB;

    return 0;
}
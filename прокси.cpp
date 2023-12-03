#include <iostream>
#include <string>

class Subject 
{
public:
    virtual void request() const = 0;
    virtual ~Subject() = default;
};


class RealSubject : public Subject 
{
public:
    void request() const override 
    {
        std::cout << "Реальная тема: Обработка запроса" << std::endl;
    }
};


class Proxy : public Subject 
{
public:
    Proxy(Subject* realSubject) : realSubject_(realSubject) {}

    void request() const override 
    {

        std::cout << "Прокси: Выполнение дополнительных операций" << std::endl;

        realSubject_->request();

        std::cout << "Прокси: Дополнительные операции завершены" << std::endl;
    }

private:
    Subject* realSubject_;
};

int main()
{

    setlocale(LC_ALL, "ru");


    RealSubject realSubject;

    Proxy proxy(&realSubject);

    proxy.request();

    return 0;
}
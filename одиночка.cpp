#include <iostream>

class Singleton 
{
private:

    Singleton() {}
    static Singleton* instance;

public:

    static Singleton* getInstance() 
    {
        if (!instance) 
        {
            instance = new Singleton();
        }
        else
        {
            std::cout << "Экземпляр уже есть" << std::endl;
        }
         
        return instance;
    }

    void message()
    {
        std::cout << "Единственный экземпляр" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main()
{
    setlocale(LC_ALL, "ru");

    Singleton* Instance_1 = Singleton::getInstance();

    
    Instance_1->message();

    
    Singleton* Instance_2 = Singleton::getInstance();

    return 0;
}
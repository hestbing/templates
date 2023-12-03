#include <iostream>
#include <string>


class Product
{
public:
    virtual std::string getName() const = 0;
};


class ConcreteProduct : public Product 
{
public:
    std::string getName() const override 
    {
        return "Конкретный продукт";
    }
};

class Creator 
{
public:
    virtual Product* createProduct() const = 0;

    void useProduct() const 
    {
        Product* product = createProduct();
        std::cout << "Использование продукта: " << product->getName() << std::endl;
        delete product;
    }
};

class ConcreteCreator : public Creator 
{
public:
    Product* createProduct() const override
    {
        return new ConcreteProduct();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Creator* creator = new ConcreteCreator();
    creator->useProduct();

    delete creator;

    return 0;
}
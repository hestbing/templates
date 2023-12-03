#include <iostream>
#include <string>


class Product 
{
public:
    void setPartA(const std::string& partA) 
    {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) 
    {
        partB_ = partB;
    }

    void setPartC(const std::string& partC)
    {
        partC_ = partC;
    }

    void show() const
    {
        std::cout << "Части: " << partA_ << ", " << partB_ << ", " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};


class Builder 
{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() const = 0;
};


class ConcreteBuilder : public Builder
{
public:
    void buildPartA() override 
    {
        product_.setPartA("Часть А");
    }

    void buildPartB() override 
    {
        product_.setPartB("Часть В");
    }

    void buildPartC() override
    {
        product_.setPartC("Часть С");
    }

    Product getResult() const override 
    {
        return product_;
    }

private:
    Product product_;
};


class Director
{
public:
    void construct(Builder& builder) 
    {
        builder.buildPartA();
        builder.buildPartB();
        builder.buildPartC();
    }
};

int main()
{

    setlocale(LC_ALL, "ru");


    ConcreteBuilder builder;
    Director director;

    director.construct(builder);

    Product product = builder.getResult();
    product.show();

    return 0;
}
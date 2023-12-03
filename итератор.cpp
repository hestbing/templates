#include <iostream>
#include <vector>


template <typename T>
class Iterator 
{
public:
    virtual T getNext() = 0;
    virtual bool hasNext() const = 0;
    virtual ~Iterator() = default;
};


template <typename T>
class ConcreteIterator : public Iterator<T> 
{
public:
    ConcreteIterator(const std::vector<T>& collection) : collection_(collection), position_(0) {}

    T getNext() override 
    {
        if (hasNext()) 
        {
            return collection_[position_++];
        }
        return T{};
    }

    bool hasNext() const override 
    {
        return position_ < collection_.size();
    }

private:
    const std::vector<T>& collection_;
    size_t position_;
};


template <typename T, typename IteratorType>
class Collection
{
public:
    virtual IteratorType createIterator() const = 0;
    virtual ~Collection() = default;
};

template <typename T>
class ConcreteCollection : public Collection<T, ConcreteIterator<T>>
{
public:
    void addItem(const T& item)
    {
        items_.push_back(item);
    }

    ConcreteIterator<T> createIterator() const override 
    {
        return ConcreteIterator<T>(items_);
    }

private:
    std::vector<T> items_;
};


int main() 
{

    ConcreteCollection<int> concreteCollection;
    concreteCollection.addItem(1);
    concreteCollection.addItem(2);
    concreteCollection.addItem(3);

    ConcreteIterator<int> iterator = concreteCollection.createIterator();

    while (iterator.hasNext()) 
    {
        std::cout << iterator.getNext() << " ";
    }

    return 0;
}
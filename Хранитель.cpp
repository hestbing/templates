#include <iostream>
#include <string>

class Memento 
{
public:
    Memento(const std::string& state = "") : state_(state) {}

    std::string getState() const 
    {
        return state_;
    }

private:
    std::string state_;
};

class Originator
{
public:
    void setState(const std::string& state) 
    {
        state_ = state;
        std::cout << "Установить состояние: " << state_ << std::endl;
    }

    Memento createMemento() const 
    {
        return Memento(state_);
    }

    void restoreMemento(const Memento& memento)
    {
        state_ = memento.getState();
        std::cout << "Восстановить состояние: " << state_ << std::endl;
    }

private:
    std::string state_;
};

class Caretaker
{
public:
    void saveState(const Memento& memento) 
    {
        savedState_ = memento;
    }

    Memento getSavedState() const
    {
        return savedState_;
    }

private:
    Memento savedState_;
};

int main() 
{
    
    setlocale(LC_ALL, "ru");


    Originator originator;

    originator.setState("Состаяние 1");
    Memento memento = originator.createMemento();

    Caretaker caretaker;
    caretaker.saveState(memento);

    originator.setState("Состаяние 2");

    originator.restoreMemento(caretaker.getSavedState());

    return 0;
}
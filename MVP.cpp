#include <iostream>
#include <string>


class Model 
{
private:
    std::string data;

public:
    const std::string& getData() const 
    {
        return data;
    }

    void setData(const std::string& newData)
    {
        data = newData;
    }
};


class Presenter
{
private:
    Model* model;
    void updateView() const 
    {
        std::cout << "Вид: Отображение данных - " << model->getData() << std::endl;
    }

public:
    Presenter(Model* model) : model(model) {}

    void updateModel(const std::string& newData) 
    {
        model->setData(newData);
        updateView();
    }
};


class View 
{
public:
    void displayData(const std::string& data) const
    {
        std::cout << "Вид: Отображение данных - " << data << std::endl;
    }
};


int main()
{

    setlocale(LC_ALL, "ru");


    Model model;
    Presenter presenter(&model);
    View view;

    presenter.updateModel("Новые данные");

    return 0;
}
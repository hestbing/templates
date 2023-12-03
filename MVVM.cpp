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


class ViewModel 
{
private:
    Model* model;

public:
    ViewModel(Model* model) : model(model) {}

    void updateData(const std::string& newData) 
    {
        model->setData(newData);
    }

    const std::string& getData() const
    {
        return model->getData();
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
    ViewModel viewModel(&model);
    View view;

    viewModel.updateData("Новые данные");

    view.displayData(viewModel.getData());

    return 0;
}
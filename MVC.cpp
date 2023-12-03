#include <iostream>
#include <string>
#include <vector>


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


class View 
{
public:
    void displayData(const std::string& data) const 
    {
        std::cout << "Вид: Отображение данных - " << data << std::endl;
    }
};


class Controller
{
private:
    Model* model;
    View* view;

public:
    Controller(Model* model, View* view) : model(model), view(view) {}

    void updateData(const std::string& newData) 
    {
        model->setData(newData);
        std::string updatedData = model->getData();
        view->displayData(updatedData);
    }
};

int main()
{

    setlocale(LC_ALL, "ru");


    Model model;
    View view;
    Controller controller(&model, &view);

    controller.updateData("Новые данные");

    return 0;
}
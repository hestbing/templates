#include <iostream>
#include <unordered_map>

class Context
{
public:
    void setVariable(const std::string& name, bool value)
    {
        variables_[name] = value;
    }

    bool getVariable(const std::string& name) const
    {
        auto it = variables_.find(name);
        if (it != variables_.end())
        {
            return it->second;
        }
        return false;
    }

private:
    std::unordered_map<std::string, bool> variables_;
};

class AbstractExpression 
{
public:
    virtual void interpret(class Context& context) const = 0;
    virtual ~AbstractExpression() = default;
};


class TerminalExpression : public AbstractExpression 
{
public:
    TerminalExpression(const std::string& variable) : variable_(variable) {}

    void interpret(Context& context) const override 
    {
        bool value = context.getVariable(variable_);
        std::cout << "Терминальное выражение: " << variable_ << " является " << (value ? "Правда" : "Ложь") << std::endl;
    }

private:
    std::string variable_;
};


class NonterminalExpression : public AbstractExpression
{
public:
    NonterminalExpression(AbstractExpression* expressionA, AbstractExpression* expressionB)
        : expressionA_(expressionA), expressionB_(expressionB) {}

    void interpret(Context& context) const override 
    {
        std::cout << "Нетерминальное выражение: ";
        expressionA_->interpret(context);
        expressionB_->interpret(context);
    }

private:
    AbstractExpression* expressionA_;
    AbstractExpression* expressionB_;
};


int main() 
{
    setlocale(LC_ALL, "ru");


    Context context;
    context.setVariable("А", true);
    context.setVariable("В", false);

    AbstractExpression* terminalA = new TerminalExpression("А");
    AbstractExpression* terminalB = new TerminalExpression("В");

    AbstractExpression* nonterminal = new NonterminalExpression(terminalA, terminalB);

    terminalA->interpret(context);
    terminalB->interpret(context);
    nonterminal->interpret(context);

    delete terminalA;
    delete terminalB;
    delete nonterminal;

    return 0;
}
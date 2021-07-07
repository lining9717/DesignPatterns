#include <iostream>
#include <string>
using namespace std;

class Subsystem1
{
public:
    string operation1() const
    {
        return "Subsystem1: Ready!\n";
    }

    string operationN() const
    {
        return "Subsystem1: Go!\n";
    }
};

class Subsystem2
{
public:
    std::string Operation1() const
    {
        return "Subsystem2: Get ready!\n";
    }
    std::string OperationZ() const
    {
        return "Subsystem2: Fire!\n";
    }
};

class Facade
{
protected:
    Subsystem1 *subsystem1_;
    Subsystem2 *subsystem2_;

public:
    Facade(Subsystem1 *sub1 = nullptr, Subsystem2 *sub2 = nullptr)
    {
        subsystem1_ = sub1 != nullptr ? sub1 : new Subsystem1();
        subsystem2_ = sub2 != nullptr ? sub2 : new Subsystem2();
    }

    ~Facade()
    {
        delete subsystem1_;
        delete subsystem2_;
    }

    string operation()
    {
        string result = "Facade initializes subsystems:\n";
        result += this->subsystem1_->operation1();
        result += this->subsystem2_->Operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->subsystem1_->operationN();
        result += this->subsystem2_->OperationZ();
        return result;
    }
};

void clientCode(Facade *facade)
{
    cout << facade->operation();
}

int main(int argc, char const *argv[])
{
    Subsystem1 *sys1 = new Subsystem1();
    Subsystem2 *sys2 = new Subsystem2();

    Facade *facade = new Facade(sys1, sys2);
    clientCode(facade);
    delete facade;
    return 0;
}

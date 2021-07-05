#include <iostream>
#include <string>
#include <algorithm>

class Target
{
public:
    virtual ~Target() {}
    virtual std::string request() const
    {
        return "Target: the default target's behavior";
    }
};

class Adaptee
{
public:
    std::string specialRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target, Adaptee
{
public:
    Adapter() {}
    std::string request() const override
    {
        std::string to_reverse = specialRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

void clientCode(const Target *target)
{
    std::cout << target->request();
}

int main(int argc, char const *argv[])
{
    std::cout << "Client: I can work just fine with the Target objects:" << std::endl;
    Target *target = new Target();
    clientCode(target);
    std::cout << std::endl
              << std::endl;
    Adaptee *adaptee = new Adaptee();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:" << std::endl;
    std::cout << "Adaptee: " << adaptee->specialRequest();
    std::cout << std::endl
              << std::endl;
    std::cout << "Client: But I can work with it via the Adapter:" << std::endl;
    Adapter *adapter = new Adapter();
    clientCode(adapter);
    std::cout << std::endl;

    delete target;
    delete adaptee;
    delete adapter;
    return 0;
}

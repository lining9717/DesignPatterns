#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

enum Type
{
    PROTOTYPE_1 = 1,
    PROTOTYPE_2 = 2
};

class Prototype
{
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name) : prototype_name_(prototype_name)
    {
    }
    virtual ~Prototype() {}
    virtual Prototype *clone() const = 0;
    virtual void method(float prototype_field)
    {
        this->prototype_field_ = prototype_field;
        cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << endl;
    }
};

class ConcretePrototype1 : public Prototype
{
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_filed)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_filed)
    {
    }

    Prototype *clone() const override
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype
{
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_filed)
        : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_filed)
    {
    }

    Prototype *clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};

class PrototypeFactory
{
private:
    unordered_map<Type, Prototype *, std::hash<int>> prototypes_;

public:
    PrototypeFactory()
    {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.0);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 60.0);
    }

    ~PrototypeFactory()
    {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    Prototype *createPrototype(Type type)
    {
        return prototypes_[type]->clone();
    }
};

void clientCode(PrototypeFactory &prototype_factory)
{
    cout << "Let's create a Prototype 1" << endl;
    Prototype *prototype = prototype_factory.createPrototype(Type::PROTOTYPE_1);
    prototype->method(90);
    delete prototype;

    cout << endl;
    cout << "Let's create a Prototype 2" << endl;
    prototype = prototype_factory.createPrototype(Type::PROTOTYPE_2);
    prototype->method(10);
    delete prototype;
}

int main(int argc, char const *argv[])
{
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    clientCode(*prototype_factory);
    delete prototype_factory;
    return 0;
}

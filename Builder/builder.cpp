#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product1
{
private:
    vector<string> parts_;

public:
    void printParts() const
    {
        cout << "Product parts: ";
        for (const auto &part : parts_)
        {
            if (part == parts_.back())
                cout << part;
            else
                cout << part << ", ";
        }
        cout << endl
             << endl;
    }

    void addPart(const string part)
    {
        parts_.emplace_back(part);
    }
};

class Builder
{
public:
    virtual ~Builder() {}
    virtual void productPartA() const = 0;
    virtual void productPartB() const = 0;
    virtual void productPartC() const = 0;
};

class ConCreteBuilder1 : public Builder
{
private:
    Product1 *product;

public:
    ConCreteBuilder1() { reset(); }
    ~ConCreteBuilder1() { delete product; }

    void reset()
    {
        this->product = new Product1();
    }

    void productPartA() const override
    {
        this->product->addPart("PartA1");
    }

    void productPartB() const override
    {
        this->product->addPart("PartB1");
    }

    void productPartC() const override
    {
        this->product->addPart("PartC1");
    }

    Product1 *getProduct()
    {
        Product1 *res = this->product;
        this->reset();
        return res;
    }
};

class Director
{
private:
    Builder *builder;

public:
    void setBuilder(Builder *builder)
    {
        this->builder = builder;
    }

    void buildMinimalViableProduct()
    {
        this->builder->productPartA();
    }

    void buildFullFeatureProduct()
    {
        this->builder->productPartA();
        this->builder->productPartB();
        this->builder->productPartC();
    }
};

void clientCode(Director &director)
{
    ConCreteBuilder1 *builder = new ConCreteBuilder1();
    director.setBuilder(builder);
    cout << "Standard basic product:" << endl;
    director.buildMinimalViableProduct();

    Product1 *p1 = builder->getProduct();
    p1->printParts();
    delete p1;

    cout << "Standard full featured product:" << endl;
    director.buildFullFeatureProduct();
    Product1 *p2 = builder->getProduct();
    p2->printParts();
    delete p2;

    cout << "Custom product:" << endl;
    builder->productPartA();
    builder->productPartC();
    Product1 *p3 = builder->getProduct();
    p3->printParts();
    delete p3;

    delete builder;
}

int main(int argc, char const *argv[])
{
    Director *director = new Director();
    clientCode(*director);
    delete director;
    return 0;
}

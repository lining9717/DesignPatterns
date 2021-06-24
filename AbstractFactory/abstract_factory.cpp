#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    virtual ~Car() {}
    virtual void drive() const = 0;
};

class BenzCar : public Car
{
public:
    BenzCar()
    {
        cout << "BenzCar::BenzCar()" << endl;
    }

    void drive() const override
    {
        cout << "Drive Benz Car" << endl;
    }
};

class BmwCar : public Car
{
public:
    BmwCar()
    {
        cout << "BmwCar::BmwCar()" << endl;
    }

    void drive() const override
    {
        cout << "Drive BMW Car" << endl;
    }
};

class Ship
{
public:
    virtual ~Ship() {}
    virtual void sail() const = 0;
};

class BenzShip : public Ship
{
public:
    BenzShip()
    {
        cout << "BenzShip::BenzShip()" << endl;
    }

    void sail() const override
    {
        cout << "Sail Benz Ship" << endl;
    }
};

class BmwShip : public Ship
{
public:
    BmwShip()
    {
        cout << "BmwShip::BmwShip()" << endl;
    }

    void sail() const override
    {
        cout << "Sail Bmw Ship" << endl;
    }
};

class Factory
{
public:
    virtual Car *createCar() const = 0;
    virtual Ship *createShip() const = 0;
};

class BenzFactory : public Factory
{
public:
    Car *createCar() const override
    {
        return new BenzCar();
    }

    Ship *createShip() const override
    {
        return new BenzShip();
    }
};

class BmwFactory : public Factory
{
public:
    Car *createCar() const override
    {
        return new BmwCar();
    }

    Ship *createShip() const override
    {
        return new BmwShip();
    }
};

void clientCode(const Factory &factory)
{
    Car *car = factory.createCar();
    Ship *ship = factory.createShip();

    car->drive();
    ship->sail();

    delete car;
    delete ship;
}

int main(int argc, char const *argv[])
{
    cout << endl;
    BenzFactory *benz_factory = new BenzFactory();
    clientCode(*benz_factory);
    delete benz_factory;

    cout << endl;

    BmwFactory *bmw_factory = new BmwFactory();
    clientCode(*bmw_factory);
    delete bmw_factory;
    cout << endl;
    return 0;
}

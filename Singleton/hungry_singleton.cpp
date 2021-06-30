#include <iostream>

class Singleton
{
public:
    ~Singleton() { std::cout << "destructor called!" << std::endl; }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    static Singleton &getInstance()
    {
        return instance;
    }

private:
    Singleton()
    {
        std::cout << "constructor called!" << std::endl;
    }
    static Singleton instance;
};
Singleton Singleton::instance;

int main(int argc, char const *argv[])
{
    Singleton &instance1 = Singleton::getInstance();
    Singleton &instance2 = Singleton::getInstance();
    return 0;
}

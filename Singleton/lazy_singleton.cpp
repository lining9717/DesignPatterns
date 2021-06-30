#include <iostream>
using namespace std;

class LazySingleton
{
public:
    ~LazySingleton() { cout << "destructor called!" << endl; }
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
    static LazySingleton *getInstance()
    {
        if (m_lazy_single_instance_ptr == nullptr)
            m_lazy_single_instance_ptr = new LazySingleton();
        return m_lazy_single_instance_ptr;
    }
    void use() const { cout << "use Lazy Single" << endl; }

private:
    // class Deletor
    // {
    // public:
    //     ~Deletor()
    //     {
    //         if (LazySingleton::m_lazy_single_instance_ptr != nullptr)
    //         {
    //             delete LazySingleton::m_lazy_single_instance_ptr;
    //         }
    //     }
    // };

    LazySingleton()
    {
        cout << "constructor called!" << endl;
    }
    static LazySingleton *m_lazy_single_instance_ptr;
    // static Deletor deletor;
};

LazySingleton *LazySingleton::m_lazy_single_instance_ptr = nullptr;
// LazySingleton::Deletor LazySingleton::deletor;

int main(int argc, char const *argv[])
{
    LazySingleton *instance1 = LazySingleton::getInstance();
    LazySingleton *instance2 = LazySingleton::getInstance();
    return 0;
}

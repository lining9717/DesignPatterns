#include <iostream>
#include <memory>
#include <mutex>

class LazySingletonSafe
{
public:
    typedef std::shared_ptr<LazySingletonSafe> Ptr;
    ~LazySingletonSafe()
    {
        std::cout << "destructor called!" << std::endl;
    }
    LazySingletonSafe(const LazySingletonSafe &) = delete;
    LazySingletonSafe &operator=(const LazySingletonSafe &) = delete;
    static Ptr getInstance()
    {
        // 可能出现按双重检锁的问题！
        if (m_lazy_single_instance_ptr == nullptr)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_lazy_single_instance_ptr == nullptr)
                m_lazy_single_instance_ptr = std::shared_ptr<LazySingletonSafe>(new LazySingletonSafe);
        }
        return m_lazy_single_instance_ptr;
    }

private:
    LazySingletonSafe()
    {
        std::cout << "constructor called!" << std::endl;
    }
    static Ptr m_lazy_single_instance_ptr;
    static std::mutex m_mutex;
};

LazySingletonSafe::Ptr LazySingletonSafe::m_lazy_single_instance_ptr = nullptr;
std::mutex LazySingletonSafe::m_mutex;

int main(int argc, char const *argv[])
{
    LazySingletonSafe::Ptr instance1 = LazySingletonSafe::getInstance();
    LazySingletonSafe::Ptr instance2 = LazySingletonSafe::getInstance();
    return 0;
}

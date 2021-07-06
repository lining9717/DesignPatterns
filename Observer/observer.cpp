#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(const string &message_from_subject) = 0;
};

class Subject
{
public:
    virtual ~Subject() {}
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notify() = 0;
};

class ConcreteSubject : public Subject
{
public:
    ~ConcreteSubject()
    {
        cout << "Goodbye, I was the Subject." << endl;
    }

    void addObserver(Observer *observer) override
    {
        list_observers_.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        list_observers_.remove(observer);
    }

    void notify() override
    {
        howManyObserver();
        auto iterator = list_observers_.begin();
        while (iterator != list_observers_.end())
        {
            (*iterator)->update(message_);
            ++iterator;
        }
    }

    void createMessage(string message = "Empty")
    {
        message_ = message;
        notify();
    }
    void howManyObserver()
    {
        std::cout << "There are " << list_observers_.size() << " observers in the list." << endl;
    }

private:
    list<Observer *> list_observers_;
    string message_;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject &subject) : subject_(subject)
    {
        this->subject_.addObserver(this);
        cout << "Hi, I'm the Observer \"" << ++ConcreteObserver::static_number_ << "\"." << endl;
        number_ = static_number_;
    }
    ~ConcreteObserver()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void update(const string &message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
        printInfo();
    }
    void printInfo()
    {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << endl;
    }

    void removeFromTheList()
    {
        subject_.removeObserver(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list." << endl;
    }

private:
    string message_from_subject_;
    static int static_number_;
    int number_;
    Subject &subject_;
};

int ConcreteObserver::static_number_ = 0;

void clientCode()
{
    ConcreteSubject *concretesubject = new ConcreteSubject();
    ConcreteObserver *concreteobserver1 = new ConcreteObserver(*concretesubject);
    ConcreteObserver *concreteobserver2 = new ConcreteObserver(*concretesubject);
    ConcreteObserver *concreteobserver3 = new ConcreteObserver(*concretesubject);
    ConcreteObserver *concreteobserver4;
    ConcreteObserver *concreteobserver5;

    concretesubject->createMessage("Hello World! ");
    concreteobserver3->removeFromTheList();

    concretesubject->createMessage("The weather is hot today! :p");
    concreteobserver4 = new ConcreteObserver(*concretesubject);

    concreteobserver2->removeFromTheList();
    concreteobserver5 = new ConcreteObserver(*concretesubject);

    concretesubject->createMessage("My new car is great! ;)");
    concreteobserver5->removeFromTheList();
    concreteobserver4->removeFromTheList();
    concreteobserver1->removeFromTheList();

    delete concretesubject;
    delete concreteobserver1;
    delete concreteobserver2;
    delete concreteobserver3;
    delete concreteobserver4;
    delete concreteobserver5;
}

int main(int argc, char const *argv[])
{
    clientCode();
    return 0;
}

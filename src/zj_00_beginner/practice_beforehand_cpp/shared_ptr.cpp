#include<memory>
#include<iostream>

class MyClass 
{
public:
    MyClass()   { std::cout << "Constructor" << std::endl; }
    ~MyClass()  { std::cout << "Destructor" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> p1(new MyClass());

    std::cout << p1.use_count() << std::endl;

    std::shared_ptr<MyClass> p2(p1);
    std::cout << p1.use_count() << ", " << p2.use_count() << std::endl;

    std::shared_ptr<MyClass> p3(std::move(p1));
    std::cout << p1.use_count() << ", " << p2.use_count() << std::endl;
}
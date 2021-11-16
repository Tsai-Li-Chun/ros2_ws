#include<memory>
#include<iostream>

struct A;
struct B;
struct A
{  
    std::weak_ptr<B> pointer;  
    ~A()
    {  
        std::cout << "A clear" << std::endl;  
    }
};  
struct B
{
    std::weak_ptr<A> pointer;  
    ~B()
    {  
        std::cout << "B clear" << std::endl;  
    }  
};
int main()
{
    auto a = std::make_shared<A>();  
    auto b = std::make_shared<B>();  
    a->pointer = b;  
    b->pointer = a;  
}
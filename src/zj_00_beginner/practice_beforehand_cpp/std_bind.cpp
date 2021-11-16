#include <iostream>
#include <functional>

void fun(int a, int b)
{
    std::cout << a << " , " << b << std::endl;
}
class Test 
{
public:
    void test_function_param(int a, int b) 
    {
        std::cout << "class: " << a << " , " << b << std::endl;
    }
    void test_function_noparam(void) 
    {
        std::cout << "class: no param" << std::endl;
    }
    void bind_testfun_np(void)
    {
        auto btf_np = std::bind( &Test::test_function_noparam, this );
        std::cout << "bind "; btf_np();
    }
};

int main(int argc, char* argv[])
{
    auto func1 = std::bind(fun, std::placeholders::_2, std::placeholders::_1);
    func1(1, 2);

    auto func2 = std::bind(fun, 9, std::placeholders::_3);
    func2(1,1,6,1,1,1,1,1,1);

    Test t;

    auto func3 = std::bind( &Test::test_function_param,t, std::placeholders::_2, std::placeholders::_1 );
    func3(8,7);

    auto func4 = std::bind( &Test::test_function_noparam,t );
    func4();

    t.bind_testfun_np();

    return 0;
}
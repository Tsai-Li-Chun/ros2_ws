#include <iostream>
#include <string>

template<typename T>
void fun1(T a, T b)
{
    std::cout << sizeof(T) << "-Byte" << std::endl;
    std::cout << a << ' ' << b << std::endl << std::endl;
}
void fun1(char a, int b)
{
    std::cout << "no template: ";
    std::cout << a << ' ' << b << std::endl << std::endl;
}

template<typename T>
class Test
{
public:
    Test(const T& a, const T& b)
    {
        this->a = a;
        this->b = b;
    }
    T test_sum(void)
    {
        std::cout << "class: " << sizeof(T) << "-Byte: ";
        return a+b;
    }
private:
    T a,b;
};

int main(int argc, char* argv[])
{
    fun1(1, 2);
    fun1('C', 9);
    fun1('A', 'R');
    fun1("TsaiLiChun", "ROS2_C++_Template");

    Test<int> t1(8,7);
    std::cout << t1.test_sum() << std::endl;
    Test<double> t2(8,7);
    std::cout << t2.test_sum() << std::endl;
    Test<char> t3('1','2');
    std::cout << t3.test_sum() << std::endl;
    Test<std::string> t4("TsaiLiChun ","Template");
    std::cout << t4.test_sum() << std::endl;
    return 0;
}
#include <iostream>
using namespace std;

/*  */
template<typename T>
void fun1(T a, T b)
{
    cout << sizeof(T) << "-Byte" << endl;
    cout << a << ' ' << b << endl << endl;
}
// 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
void fun1(char a, int b)
{
    cout << "no template" << endl;
    cout << a << ' ' << b << endl << endl;
}

int main(int argc, char* argv[])
{
    fun1(1, 2);
    fun1('C', 9);
    fun1('A', 'R');
    fun1("TsaiLiChun", "ROS2_C++_Template");
    return 0;
}
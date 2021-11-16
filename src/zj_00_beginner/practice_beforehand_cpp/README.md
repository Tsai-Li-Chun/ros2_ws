---
tags: ROS2-foxy,ubuntu20
---
ubuntu20下開發ROS2 - 2.5 正式研發ROS2-pkg包之前的注意事項
===

首先，上一篇教學中建立的pkg可以刪了，反正只是用來了解觀念用的，而且pkg名子my_package很醜，所以刪了。

步驟：
1. 刪除上一篇教學建立的pkg，my_package
2. 刪除上一篇教學中下載的教學用海龜pkg，我們放在ThirdParty_pkg裡，turtlesim
3. 下編譯指令，應該要無錯誤
4. 刪除工作空間裡的 build install log 3個檔案
5. 下編譯指令，應該要無錯誤

:::warning
:zap: **從這一篇開始建立的 pkg 和 node 開始會正式加入git版控，所以名稱什麼儘量事先規範好，不要事後一直更改**
目前設定的規範
1. pkg名稱依照 創建時間 & 內容淺深 & 專案進度，前置數字編號來代表順序，但因禁止開頭數字，所以目前暫定名稱為 **zj_xx_pkg內容** ，zj代表利君，xx為數字編號
2. node名稱無限制，故直接依照 創建時間 & 內容淺深 & 專案進度，前置數字編號來代表順序
:::
:::warning
:zap: 然後也不需要有的終端有載入ros2_ws的local_setup.bash有的不用，統一都要載入，所以直接在 **.bashrc** 裡加入
source ~/ros2_ws/install/local_setup.bash
:::

---

接下來的應該都會撰寫 發佈 訂閱 服務 msg param 等用於初學者了解ROS2用的node，創建時間最早，內容最初學者，專案進度最起點，所以給的數字編號 "00"。
開終端機，進 **ros2_ws / src** 目錄資料夾裡，依照阿君自定義的規範下指令來創建pkg
```
ros2 pkg create --build-type ament_cmake zj_00_beginner
```
然後編譯，無錯誤後工作空間資料夾應長這樣
:::info
ros2_ws/
　　build/
　　install/
　　log/
　　src/
　　　　ThirdParty_pkg/
　　　　zj_00_beginner/
　　　　　　CMakeLists.txt
　　　　　　package.xml
　　　　　　include/zj_00_beginner/
　　　　　　src/
:::
之後的node的.cpp檔都會新增在 **ros2_ws / src / zj_00_beginner / src /** 裡

---

**正式撰寫ROS2程式之前，有一些程式的知識需要事先了解**
整體總目錄可參考
[ROS2導入&レクチャー](https://qiita.com/NeK/items/7ac0f4ec10d51dbca084) -> 知っといてほしい知識 的部份
[語言技術：C++ Gossip](https://openhome.cc/Gossip/CppGossip/index.html)

C++ **class應用**
---
可參考
[C++の基礎:クラス](https://www.s-cradle.com/developer/sophiaframework/tutorial/Cpp/class.html)
[C++ 定義類別](https://openhome.cc/Gossip/CppGossip/ClassABC.html)
class應用從基本的 **建立物件** 到 **繼承物件** 到 **物件模板** 到 **物件指標** 等，使用C++來開發RO2程式的話都會使用到

**很基本，而且教學碼蠻大量的，就不放範例程式了**

C++ template模板應用
---
可參考
[適当なC++テンプレート入門](https://qiita.com/hal1437/items/b6deb22a88c76eeaf90c)
[C++ 函式模版](https://openhome.cc/Gossip/CppGossip/FunctionTemplate.html)
通常應用在函數與class物件的輸入出變數的資料型態的規定
```cpp=
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
```

C++ namespace名稱空間
---
可參考
[namespaceの賢い使い方](https://qiita.com/_EnumHack/items/430da105a541f9ecd774)
[C++ 簡介名稱空間](https://openhome.cc/Gossip/CppGossip/Namespace.html)
當函數名稱發生衝突時，EX:A寫了add的funtion，B也寫了add的funtion，AB兩人的add的funtion都需留著，就可以使用namespace來區隔AB兩人的空間，通常應用在多人多團隊共同開發時的funtion區隔。

C++ lambda匿名函式
---
可參考
[ラムダ式](https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html)
[C++ lambda運算式](https://openhome.cc/Gossip/CppGossip/Lambda.html)
可將一段演算流程(通常都行數短短的1.2行簡單運算)當場進行封包成函數(匿名)，這樣就可以無需按照正式規格的去撰寫函數。

C++ std::bind使用
---
[std::bindの使い方](https://qiita.com/tkyaji/items/1aa7bb01658e848d3ef4)
[淺談 bind function](https://www.jyt0532.com/2017/01/08/bind/)

```cpp=
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
```

C++ auto,unique,shared,weak 智慧型指標
---
基本上都使用shared,weak這兩個，尤其ROS大量使用shared

C++中可以使用 ```new``` 指令新增動態記憶體給變數使用，但是後常常忘記使用 ```delete``` 刪除，智慧型指標為此而誕生，有著自動管理動態記憶體的功能，還可以共享出去等等。

ROS程式中的各種物件都是使用智慧型指標來進行運算的，尤其是 **shared_ptr** 與 **make_shared**

可參考
[C++11スマートポインタ入門](https://qiita.com/hmito/items/db3b14917120b285112f)
[C++ shared_ptr](https://openhome.cc/Gossip/CppGossip/sharedPtr.html) -> 還有其他智慧指標，請回目錄後去 **管理物件** 的部份
[スマートポインタ3](https://programming.pc-note.net/cpp/smartpointer3.html)
[C++ std::shared_ptr 用法與範例](https://shengyu7697.github.io/std-shared_ptr/)
[C++ 第４章 標準ライブラリ](https://programming-place.net/ppp/contents/modern_cpp/library/004.html)

首先來看看一般的指標，對就只是一般指標，加了.也不會出現任何結構成員or物件成員的提示
![](https://i.imgur.com/FxePvuB.png)

再來看看智慧型指標，因為是物件，加了.後會顯示出可使用的成員提示，相對創造方法的確比一般指標還複雜一點點，```ptr()```裡的```new int(10)```代表了**ptr**物件的建構函數所需要的輸入變數，使用```new```指令開闢一塊**int**大小的空間然後塞入初值10再傳入**ptr**物件裡。
![](https://i.imgur.com/omjvmKX.png)

上述有說明到智慧型指標可共享&移交&無須```delete```指令即可在程式區塊(退出函式or退出main)結束運行時自動釋放占用的記憶體區塊，如何證明? 參考這段程式
```cpp
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
```
執行結果，可以發現除了紀錄共享數量，還會在共享數量歸0(代表無人使用)時自動執行解建構函式來刪除記憶體
:::success
Constructor
1
2, 2
0, 2
Destructor
:::


智慧型指標還是會有記憶體無法釋放的情況，當然比起直接使用 ```new``` ```delete``` 來說狀況大幅改善，只需要程式開發者注意不要參照來參照去的運算，舉例來說下面的例子
[std::shared_ptr發現依然存在著資源無法釋放的問題](https://www.it145.com/9/169595.html) > 使用weak_ptr解決

接著再來看使用一般物件的創見方法時，有問題的情況
```cpp
#include <iostream>
#include <memory>

class MyClass 
{
public:
    MyClass()   { std::cout << "Constructor" << std::endl; }
    ~MyClass()  { std::cout << "Destructor" << std::endl; }
};

int main()
{
    MyClass* c = new MyClass();

    std::shared_ptr<MyClass> p1(c);
    std::shared_ptr<MyClass> p2(c);

    std::cout << p1.use_count() << ", " << p2.use_count() << std::endl;
}
```
執行結果，可以發現p1&p2均與c共享但共享數量卻只有1，且退出程式時解建構執行了2次
:::success
Constructor
1, 1
Destructor
Destructor
free(): double free detected in tcache 2
中止 (核心已傾印)
:::

目前為止可發現```shared_ptr```在創造智慧指標物件時還是需要使用```new```指令，且還需要區別出共享or繼承的來源是否也是```shared_ptr```還是只是一般物件。
所以建議搭配```make_shared```一起使用。
```make_shared```會依照輸入的模板的資料型態來創造出相對應的```shared_ptr```物件並返回，也一些對應的共享設定等也會一並處理，比起單純使用```new```來說安全的多了
```cpp
#include <iostream>
#include <memory>

class MyClass 
{
public:
    MyClass()   { std::cout << "Constructor" << std::endl; }
    ~MyClass()  { std::cout << "Destructor" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> p = std::make_shared<MyClass>();
}
```
執行結果
:::success
Constructor
Destructor
:::
事實上C++使用手冊也建議全面使用```make_shared```來創造```shared_ptr```的物件


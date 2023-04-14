#include <iostream>
#include <climits>

// 不同类型的整数
// int main()
// {
//     using namespace std;
//     int n_int = INT_MAX;
//     short n_short = SHRT_MAX;
//     long n_long = LONG_MAX;
//     long long n_llong = LLONG_MAX;

//     cout << "int is: " << sizeof(int) << "bytes." << endl;
//     cout << "short is: " << sizeof(n_short) << "bytes." << endl;
//     cout << "long is: " << sizeof(n_long) << "bytes." << endl;
//     cout << "long long is: " << sizeof(n_llong) << "bytes." << endl;

//     cout << "Maximum value: " << endl;
//     cout << "int: " << n_int << endl;
//     cout << "n_short: " << n_short << endl;

//     cin.get();
//     return 0;
// }

// // 打印不同格式的整数
// int main()
// {

//     using namespace std;
//     int chest = 42;
//     int waist = 42;
//     int inseam = 42;

//     cout << "chest: " << chest << endl;
//     cout << hex; // 不会显示任何内容
//     cout << "waist: " << waist << endl;
//     cout << oct;
//     cout << "inseam: " << inseam << endl;

//     return 0;
// }

// // 转义符号测试
// int main()
// {
//     char alarm = '\a';
//     std::cout << alarm << std::endl;
//     return 0;
// }

// // wchar_t类型的字符
// int main()
// {
//     wchar_t test = L'A';
//     std::cout << test << std::endl;
//     return 0;
// }

// // bool类型
// int main()
// {
//     std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
//     float tub = 10.0 / 3.0;
//     double mint = 10.0 / 3.0;
//     const float million = 1.0e6;

//     std::cout << "tub = " << tub;
//     std::cout << ", a million tubs = " << million * tub;

//     std::cout << ",\nand ten million tubs = ";
//     std::cout << 10 * million * tub << std::endl;

//     std::cout << "mint = " << mint << " and a million mints = ";
//     std::cout << million * mint << std::endl;
//     return 0;
// }

// 浮点数运算导致精度降低的例子
int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;

    return 0;
}

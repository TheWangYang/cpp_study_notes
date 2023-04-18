#include <iostream>
#include <cstring>

// int main()
// {
//     using namespace std;
//     int yams[3];
//     yams[0] = 1;
//     yams[1] = 2;
//     yams[2] = 3;

//     int yamscosts[3] = {20, 30, 45};

//     cout << "Total yams = " << endl;
//     cout << yams[0] + yams[1] + yams[2] << endl;
//     cout << "The package with " << yams[1] << " yams costs ";
//     cout << yamscosts[1] << " center per yam.\n";
//     int total = yams[0] * yamscosts[0] + yams[1] * yamscosts[1];
//     total = total + yams[2] + yamscosts[2];

//     cout << "The total yam expense is " << total << " cents.\n";

//     cout << "\nSize of yams array = " << sizeof(yams);
//     cout << " bytes.\n";
//     cout << "Size of one element = " << sizeof(yams[0]);

//     cout << " bytes.\n";
//     return 0;
// }

// int main()
// {
//     using namespace std;
//     const int Size = 15;
//     char name1[Size];
//     char name2[Size] = "C++owboy";

//     cout << "Howdy! I'm " << name2;
//     cout << "! What's your name?\n";
//     cin >> name1;
//     cout << "Well. " << name1 << ", your name has ";
//     cout << strlen(name1) << " letters and is stored\n";
//     cout << "in an array of " << sizeof(name1) << " bytes.\n";
//     cout << "Your initial is " << name1[0] << ".\n";
//     name2[3] = '\0';
//     cout << "Here are the first 3 characters of my name: ";
//     cout << name2 << endl;
//     return 0;
// }


// // 4.4程序清单
// int main(){
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];
//     cout << "Enter your name:\n";
//     cin.getline(name, ArSize);
//     cout << "Enter your favorite dessert:\n";
//     cin.getline(dessert, ArSize);
//     cout << "I have some deliecious: " << dessert;
//     cout << " for you, " << name << ".\n";
//     return 0;
// }


// // 4.5程序清单
// int main(){
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout << "Enter your name:\n";
//     cin.get(name, ArSize).get();
//     cout << "Enter your favorite dessert:\n";
//     cin.get(dessert, ArSize).get();
//     cout << "I have some delicious " << dessert;
//     cout << " for you, " << name << ".\n";
//     return 0;

// }


// //4.11程序清单
// struct inflatable
// {        
//     char name[20];
//     float volume;
//     double price;
//     std::string str_test;
// };

// int main(){
//     using namespace std;
//     inflatable test1 = {
//         "test test",
//         1.88,
//         29.99,
//         "this is string from test1."
//     };

//     inflatable test2 = {
//         "test2",
//         898,
//         899,
//         "this a string from test2."
//     };

//     cout << "test1 name: " << test1.name << endl;
//     cout << "test1 string: " << test1.str_test << endl;


//     cout << "test2 name: " << test2.name;
//     cout << "test2 string: " << test2.str_test << endl;

//     return 0;
// }



// 4.14指针使用
// int main(){
//     using namespace std;
//     int number = 8;
//     double double_number = 10.0;

//     cout << "number value = " << number << endl;
//     cout << "number value address = " << &number << endl;

//     cout << "double_number address = " << &double_number << endl;
//     return 0;
// }



// // 4.15指针使用示例
// int main(){
//     using namespace std;
//     int updates = 6;
//     int *p_updates;
//     p_updates = &updates;


//     cout << "updates = " << updates << endl;
//     cout << ", *p_updates = " << *p_updates << endl;


//     cout << "Address: &updates = " << &updates << endl;
//     cout << "Address using p_updates = " << p_updates << endl;

//     *p_updates = *p_updates + 1;
//     cout << "new updates using *p_updates + 1 = " << *p_updates << endl;

//     return 0;
// }


// // 4.17程序清单，演示new运算符的使用
// int main(){
//     using namespace std;
//     int nights = 1001;
    
//     int* pt = new int;
//     *pt = 1001;

//     cout << "nights value = " << nights << ", location = " << &nights << endl;
//     cout << "one int value = " << *pt << ", its location = " << pt << endl;

//     return 0;
// }

// // 4.18动态数组的使用
// int main(){
//     using namespace std;
//     double* p3 = new double[3];

//     p3[0] = 0.1;
//     p3[1] = 0.2;
//     p3[2] = 0.3;

//     cout << "p3[0] = " << p3[0] << endl;

//     p3 = p3 + 1;

//     cout << "now p3[0] = " << p3[0] << endl;

//     p3 = p3 - 1;
//     delete [] p3;

//     return 0;
// }

// 4.19程序示例
int main(){
    using namespace std;
    double wages[3] = {10000.0, 300.5, 5000.0};
    short stacks[3] = {3, 2, 1};

    double* pw = wages;
    short* ps = stacks;


    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw  << ", *pw = " << *pw <<endl;

    return 0;
}



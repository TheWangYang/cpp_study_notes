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


//4.11程序清单
struct inflatable
{        
    char name[20];
    float volume;
    double price;
    std::string str_test;
};

int main(){
    using namespace std;
    inflatable test1 = {
        "test test",
        1.88,
        29.99,
        "this is string from test1."
    };

    inflatable test2 = {
        "test2",
        898,
        899,
        "this a string from test2."
    };

    cout << "test1 name: " << test1.name << endl;
    cout << "test1 string: " << test1.str_test << endl;


    cout << "test2 name: " << test2.name;
    cout << "test2 string: " << test2.str_test << endl;

    return 0;
}

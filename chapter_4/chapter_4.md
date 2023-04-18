## 复合类型

### 数组

数组的声明：

1. 存储在每个元素中的值的类型；
2. 数组名；
3. 数组中的元素数；

例如：

```
short months [12];
```

上述数组size应当为编译时已知的数，使用new可以实现动态设定数组size；

```
long keep [] = {1, 2, 3}
```

编译器会将上述数组keep的size指定为4；

C++11中对数组初始化时，可以省略=号，例如下述代码：

```
double earnings [4] {1.2e4, 1.6e4, 1.1e4, 1.7e4};


unsigned int couts[10] = {};


float balances[100]{};
```

上述第2、3行代码表示将数组中元素都赋值为0；

同时，列表初始化禁止缩窄转换：

```
long tmp[] = {25, 92, 2.3};

char slifs[4] {'h', 'i', 1122011, '\0'};

char tlifs[4] {'h', 'i', 112, '\0'};
```

第一行代码不可以编译成功是因为，元素2.3为float类型，转换为long数组中的long类型是不被允许的；

第二行代码是因为1122011超过了char的范围；

C++STL库中，提供了数组的替代品，模板类vector<>

## 字符串

C中表示字符串的方法：

```
char s1 [8] = {'b', 'e', ..., 'I'};//这不是一个字符串

cahr s2[8] = {'n', ... , '\0'};//这是一个字符串
```

使用字符串常量或字符串面值来表示字符串：

```
char tmp[11] = "";

char fish[11] = "";
```

使用"号括起的字符串隐式地包括结尾的空字符；

C++中"S"实际上表示字符串所在的内存地址；

```
char tmp = "S";//将会编译失败
```

注意：两个字符串s1 s2进行拼接时，第二个字符串的第一个字符会替换掉第一个字符串的末尾技术的'\0'；

cin使用空白（空格、制表符、换行符）来确定字符串的结束位置；

### 每次读取一行字符

面向行的输入：getline()
使用回车键入的换行符来确定输入的结尾，使用cin.getline()即可，但是cin.getline()不保存换行符；

面向行的输入：get()，其不再丢弃换行符，而是留在输入队列中；
cin.get()使用如下方法处理换行符：

```
cin.get(name, ArSize);
cin.get();
cint.get(dessert, ArSize);
```

还可以将两个get()函数拼接起来使用：

```
cin.get(name,ArSize).get();
```

这样使用是因为，使用cin.get()返回了一个cin对象，然后返回的cin对象继续调用get()函数；

同样，cin.getline()也可以使用如下方法读入：

```
cin.getline(name,ArSize).getline();
```

cin.get()函数表现出来的不同参数列表，是C++中的函数重载；

使用cin.get()使得读取输入更加精细，如果输入读取中断是因为数组长度原因，那么使用cin.get()得到的将不是一个空字符，如果输入中断是因为get()读取到了空字符的原因，那么继续使用cin.get()得到的下一个字符是空字符或换行符；

### 空行和其他问题

使用cin.get()读取到空行时将会发生阻断，使用cin.clear();可以避免这种情况；

如果输入字符串比分配的空间长，那么getline()和get()将会把余下的字符留在输入队列中，同时getline()还会设置失效位，并关闭后边的输入；

### 混合输入字符串和数字

```
cin.get(year).get();
(cin >> year).get();
```

## string类介绍

C++98标准通过添加string类扩展了C++库；
类设计可以让程序自动处理string的大小；

### C++11字符串初始化

```
string tmp = {"test test test"};
```

### 赋值/拼接/附加

不能将一个数组赋值给另一个数组但是可以将一个string str1 = str2;

### string类别的其他操作

C++出现string类前，还可以使用strcpy(char1, char2);将来char2表示的字符赋值给char1；
使用strcat()将字符串附加到字符数组末尾；

### 得到string对象的长度

int len1 = str1.size();
int len2 = strlne(char1);

### string str; cin >> str;存在的友元函数使用

### 其他形式的字符串字面值

```
wchar_t tiltle[] = L"xxx xxx";
char16_t name[] = u"eeee  eee";
char32_t car[] = U"eeee eee";
```

使用R来标识原始字符串；

```
cout << R"(txtxt txtx) "\n" "\n" afafd. endl." << '\n';
输出为：(txtxt txtx) \n \n afafd. endl.
```

```
cout < R"+*("(txtxttx txttx )", shaihsa.)+*" << endl;
输出为："(txtxttx txttx )", shaihsa.
```

上述使用+*()+*代替了默认的界定符()；

## 结构简介

C++中结构是一种比元素更加灵活的数据格式；

创建基本的结构如下：

```
struct test{
    char name[20];
    float volume;
    double price;
}
```

上述代码创建了test这种类型的结构体；
使用上述结构体创建变量；

```
test t1;
test t2;
```

注意：访问类成员函数（例如：cin.getline()）是从访问结构成员变量的方式衍生而来的；

### C++11结构初始化

```
inflatable test {"test", 78.09, 88};(=号是可选的)
```

如果在初始化结构体的时候，大括号内没有包含任何东西，那么各个成员都将被设置为零；
对于结构体中的成员是char等类型数组的，该成员被设置为0字节；

### C++支持将string类型对象作为结构体的成员

```
struct inflatable
{        
    char name[20];
    float volume;
    double price;
    std::string str_test;
};
```

### 同时完成定义结构体和创建结构体变量工作

```
struct test{
    int key_number;
    std::string test;
} test1, test2;
```

还可以使用这种方式创建变量：

```
struct test{
    std::string str_test;
    int number;
} test1 = {
    "test",
    120
};
```

还可以声明没有名称的结构类型：

```
struct{
    int number;
    std::string test;
} position;
```

### 结构数组

```
inflatable test[100];
```

初始化结构数组：

```
inflatable test[2] = {
    {"test1", 120},
    {"test2", 130}
};
```

### 结构中的位字段

```

struct test{
    unsigned int SN : 4;
    unsigned int : 4;
    bool goodIn : 4;
    bool goodTorgle : 4;
};
```

可以使用如下方法初始化这些字段：

```
test t1 = {14, true, false};
```

位字段通常用在低级编程中。
可以使用整型或者按位运算符来代替这种方式；

### 共用体union

共用体union是一种数据格式，可以存储不同的数据类型，但同时只能存储一种类型；

```
union test {
    int number;
    long long_number;
    double double_number;
}
```

```
test t1;
t1.nuber = 15
cout << t1.number;
t1.double_number = 19.0;
cout << t2.double_number;
```

union同时只能存储一个值；

能用到union的地方：

```
struct widget {
    char brand[20];
    int type;
    union id{
        long id_num;
        char id_char[20];
    } id_value;
};


widget prize;

if(prize.type == l){
    cin >> prize.id_value.id_num;
}else{
    cin >> prize.id_value.id_char;
}
```

### 匿名共用体（anonymous union）

匿名共用体没有名称，其成员将成为位于相同地址处的变量；

```
struct widget{
    char brand[20];
    int type;
    union {
        long id_num;
        char id_char[20];
    };
};



widget price;

if(prize.type == 1){
    cin >> prize.id_num;
}else{
    cin >> prize.id_char;
}
```

使用匿名共同体时，程序员需要确定哪个成员是活动的；

共用体常用于节省内存；
共用体常用于系统数据结构或硬件数据结构；

## 枚举

C++中的enum提供了一种创建符号常量的方式，这种方式可以替代const；
enum还允许定义新的类型；

```
enum test {red, orange, yellow, ...}
```

上述语句完成两项工作；
使得test成为新类型的名称，其中test被称为枚举；
使得red, orange等成为符号常量，对应整数值0-7，这些常量叫做枚举量；

```
test band;
```

在不进行强制类型转换时，只能将定义枚举时使用的枚举量赋给这种枚举的变量；

```
band = blue;
band = 2000;//是错误的
```

枚举量是整型，可以被提升为int类型，但是int类型不能自动转换为枚举类型；

```
band = 3;//合法的
color = 3 + red;//非法的
band = red + greeen;//后边的red+green是合法的，但是相加之后得到的是int类型的数，赋值给枚举类是非法的
```

如果int值是有效的，那么使用强制类型转换是可以赋值给枚举变量的：

```
band = test(3);
band = test(400003);//不会出错，但是不会得到可靠的结果；
```

可以用枚举类来定义switch中使用的符号常量；

### 设置枚举量的值

enum Test{red = 0, green = 1, ...};

指定的值必须是整数；

还可以创建多个值相同的枚举量：

```
enum {zero, number = 0, ...};
```

### 枚举的取值范围

通过强制类型转换，可以将取值范围中的任何整数值赋值给枚举变量，即使这个值不是枚举值：

```
enum bits{one = 1, two = 2, ... , eight = 8};

bits myflag;


myflag = bits(6);
```

其中6虽然不是枚举值，但是位于枚举值定义的取值范围内；

枚举类的取值范围的上限确定：找到大于枚举类中最大值的，最小的2的幂次，然后减1就是枚举类的取值上限；

枚举类取值范围的下限确定：如果枚举类中最小值为0，那么就是0；如果为负数，那么使用和找上限相同的方法，但是注意加上负号；

注意：选择使用多少空间来存储枚举由编译器决定。

对取值较小的枚举类使用一个字节或更少的空间；
而对于包含long类型值的枚举，使用4个字节；

## 指针和自由存储空间

指针存储的是变量的地址而不是值本身；

使用&来得到变量的地址，就可以得到的对应的位置；

```
int main(){
    using namespace std;
    int number = 8;
    double double_number = 10.0;

    cout << "number value = " << number << endl;
    cout << "number value address = " << &number << endl;

    cout << "double_number address = " << &double_number << endl;
    return 0;
}
```

上述cout打印出来的变量地址使用十六进制表示法；

注意：有些系统可能不会把两个变量存储在相邻的内存单元中；

使用常规变量时，值是指定的量，而地址为派生量；

C++中采用关键字new请求正确数量的内存以及使用指针来跟踪新分配的内存的位置；

使用*运算符被称为间接值，或解除引用运算符，将其应用于指针，可以得到该地址处存储的值；

指针使用示例：

```
int main(){
    using namespace std;
    int updates = 6;
    int *p_updates;
    p_updates = &updates;


    cout << "updates = " << updates << endl;
    cout << ", *p_updates = " << *p_updates << endl;


    cout << "Address: &updates = " << &updates << endl;
    cout << "Address using p_updates = " << p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "new updates using *p_updates + 1 = " << *p_updates << endl;

    return 0;
}
```

### 声明和初始化指针

指针声明的时候需要制定指针准备指向的数据的类型。

```
int * p_updates;
```

可以说p_updates是指向int类型的指针；
*p_updates是int类型的；

C++程序员使用如下格式定义指针：

```
int* pointer;
```

C程序员使用如下格式定义指针：

```
int *point;
```

int*是一种类型，指向int的指针；

下面的声明创建一个指针p1和一个int变量p2；

```
int* p1, p2;
```

对每个指针变量都需要使用int*来指定；

### 指针的危险

C++中创建指针时，计算机系统将分配用来存储地址的内存，但不会分配用来存储指针所指向数据的内存；

```
long* fellow;
*fellow = 223333;
```

上述将数据223333放置到*fellow指针创建时随机对应的地址上；

### 指针和数字

使用如下强制类型转换可以实现将数字赋值给指针：

```
int* pointer;
pointer = (int*)0xB80000;
```

### 使用new来分配内存

指针真正的使用地方在于，可以在运行阶段，分配未命名的内存以存储值，这种情况只能通过指针来访问内存；

```
int* ptr = new int;
```

new int告诉程序，需要适合存储int类型值的内存，然后程序寻找到一个适合存储int类型数据的内存并把对应的地址赋值给ptr；

使用上述ptr指针指向对应的数据对象（数据对象指的是为数据项分配的内存块）；
变量也是数据对象；

```
// 4.17程序清单，演示new运算符的使用
int main(){
    using namespace std;
    int nights = 1001;
    
    int* pt = new int;
    *pt = 1001;

    cout << "nights value = " << nights << ", location = " << &nights << endl;
    cout << "one int value = " << *pt << ", its location = " << pt << endl;
    
    return 0;
}
```

对于指针，使用new分配的内存块通常与常规变量声明分配的内存块不同，变量的值被存储在栈stack的内存区域中；
使用new声明的指针对应的值存储在堆heap内存区域或自由存储区中；

C++中值为0的指针被称为null ptr指针；

### 使用delete释放内存

使用完内存之后，可以使用delete将对应的内存返还给内存池中；

```
int* ptr = new int;

delete ptr;
```

上述代码可以释放ptr指向的内存，但是不会删除指针ptr本身；

注意：一定要配对的使用new 和 delete，否则会发生内存泄漏；

注意：不能使用delete来释放常规声明变量所获得的内存：

```
int* ps = new int;
delete ps;
delete ps;//不允许重复释放，将会发生不确定的事情

int judge = 5;
int* pt = &judge;
delete pt;//不允许
```

### 使用new来创建动态数组

在编译时给数组分配内存称为静态联编（static binding）；
使用静态联编时，必须在编写程序时指定数组的长度；
使用动态联编时，程序在运行时确定数组的长度；

```
int* psome = new int[10];
```

new运算符返回第一个元素的地址，该地址被赋值给指针psome；

使用如下命令释放内存：

```
delete [] psome;
```

上述的方括号表示，应释放整个数组，而不是指针指向的元素；

### 使用动态数组

```
int* psome = new int[10];
```

psome向后移动4个字节之后将指向数组中的下一个元素；

实际上一种访问数组元素所有方法：只需要将指针当作数组名使用index下标进行访问即可；

```
// 4.18动态数组的使用
int main(){
    using namespace std;
    double* p3 = new double[3];

    p3[0] = 0.1;
    p3[1] = 0.2;
    p3[2] = 0.3;

    cout << "p3[0] = " << p3[0] << endl;

    p3 = p3 + 1;

    cout << "now p3[0] = " << p3[0] << endl;

    p3 = p3 - 1;
    delete [] p3;

    return 0;
}
```

### 指针、数组和指针算术

指针+1之后，增加的量为其指向的类型的字节数；

C++将数组名解释为地址；

```
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
```

C++中将stacks[1]看做*(stacks+1)；

注意：sizeof(arrayname)时，C++不会将数组名字解释为地址；

数组名被解释为第一个元素的地址，而对数组名应用地址元素符时，得到的是整个数组的地址；

```
&tell等价于&tell[0];
shot tell[10];
short (*ps) [20] = &tell;//这表示将short类型的10长度的数组的地址给ps指针；
```

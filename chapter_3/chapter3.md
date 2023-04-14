## 处理数据

C++中类型分为两种：基本类型和复合类型；

基本类型分为：整数和浮点数；

复合类型：数组、字符串、指针和结构；

### 简单变量

```
int test;
test = 5;
```

这里程序会自动找到一块适合存放整数的内存，并将5复制到该单元中；
实际上使用&来检索test的内存地址；

### C++中的命名规则

1. 在名称中只能使用字母字符、数字和下划线；
2. 名称的第一个字符不能是数字；
3. 区分大小写字符与小写字符；
4. 不能将C++关键字用作名称；
5. 以两个下划线或下划线和大写字母打头的名称被保留给实现（编译器及其使用的资源）使用。以一个下划线开头的名称被保留给实现，用作全局标识符；
6. C++对名称的长度没有限制，名称中所有的字符都有意义，但有些平台有长度限制；

### 常见的变量命名方式

```
str/sz表示以空字符结束的字符串；
b表示布尔值；
p表示指针；
c表示单个字符；
```

### C++中的整型数据

按照宽度递增的顺序排列（即按照占用内存的大小）：
char、short、int、long、C++11中新增的long long；
这其中每种类型都有有符号版本和无符号版本；

注意：char常用来表示字符而不是数字；

short最少16位；
int至少与short一样长；
long至少32位，且至少与int一样长；
long long至少64位，且至少与long一样长；

实际上：short是short int的简称，long是long int的简称；

上述四种类型的数据都是有符号数据，意味着取负数和正数的范围是一样的；

sizeof运算符返回类型和变量的长度，单位是字节；

```
注意：使用sizeof运算符时，对变量可以放入带括号例如：
int test;
sizeof(test)或sizeof test
但是使用int类型名时，需要带上括号：
sizeof(int)
```

### define预编译指令

```
#define test = 22222
```

在将上述程序交给预处理器之前，告诉预处理器将源代码中的所有test变量替换为2222
预处理器只会将其中的独立的单词替换为2222；

C++中使用const定义符号常量，因此不会经常使用#define来定义符号常量；

C++中还有另外一种初始化的方法：

```
传统的初始化方法：int owls;
相比于C语言，C++中独有的初始化方法：int wrenes(432);
```

C++中另外一种初始化的方式：

```
int hamburgers = {245};
```

C++11中，使用如下方式定义变量：

```
int emus{6};
int reals = {12};

其次，大括号内可以不包含任何东西，这种情况下，变量会被初始化为0：
int test = {};
int test {};
```

这种初始化方式有助于更好地防范类型转换错误；

### 无符号类型

仅当数值不会为负数时，才应使用无符号类型；
需要创建无符号版本的基本整型，只需要使用unsigned关键字来修改声明即可；
例如：

```
unsigned int
unsigned float
unsigned double
unsigned long
unsigned long long
```

注意：使用有符号和无符号数时，如果超过了范围，那么该变量就会从当前类型的范围的另一端开始取值，例如：

```
int test1 = 32767;
test1 = test1 + 1;
unsigned int test2 = 0;
test2 = test2 - 1;

cout << test1 << endl;
cout << test2 << endl;
```

那么，第一行打印为-32768，第二行打印为65535;

C++中保证了无符号整数的正常越界行为，但是不保证有符号整数的这种越界行为；

在默认情况下，cout使用10进制显示整数；

### 使用cout << hex; cout << oct;更改cout显示整数的进制方式

```
// 打印不同格式的整数
int main()
{

    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "chest: " << chest << endl;
    cout << hex; // 不会显示任何内容
    cout << "waist: " << waist << endl;
    cout << oct;
    cout << "inseam: " << inseam << endl;

    return 0;
}
```

默认行为：C++中，默认将整型常量（如果不超过范围的话）存储为int类型；

### 常量的后缀

在C++中具体将数字存为什么类型，需要看数字的后缀，例如：

```
22022L表示将该数字存为long类型的数字；
22022被存储为int类型；
22022LU表示被存储为unsigned long类型的数字；
22022LL表示被存为long long类型的数字；
22022ull/Ull/ULL表示被存为unsigned long long类型的数字；
```

C++中对不带后缀的十进制数，具有特殊的处理，将使用int，long，long long，short中能够存储该数字的最小类型来表示；

对不带后缀的十六进制或八进制整数，将使用int，unsigned int long， unsigned long，long long或unsigned long long其中的最小类型来表示；
这是因为十六进制常用来表示地址，而地址是没有符号的；所以使用unsigned int比long更适合来表示地址；

### char类型：字符和小整数

char足够长，可以表示目标计算机中的所有基本符号：所有的字母、数字、标点符号等；实际上很多系统支持的字符都不超过128个；

cout和cin的行为都是由变量类型引导的；这是C++中智能对象的一个例子；

### cout.put()成员函数

.被称为C++中的成员运算符；
cout.put()提供了另外一种显示字符的方法，可以代替<<运算符；
在C++ release 2.0之前，C++中打印字符使用：cout.put('ch')，因为那时，使用cout << 'ch';得到的是ch对应的ASCII码；

### signed char 和 unsigned char

char在默认情况下，既不是没有符号，也不是有符号；是否有符号由C++实现决定；
char如果需要存储ASCII标准字符，则char有没有符号都是可以的；

### wchar_t

wchar_t表示宽字符类型，可以用来表示扩展字符集；
wchar_t是一种整数类型，有足够的空间，可以表示系统使用的最大扩展字符集；
这种类型与另外一种整型underlying类型的长度和符号属性是相同的；

iostream中提供了最新版本用于处理wchar_t的工具：wcin和wcout；
另外，可以在字符前加上L来表示为wchar_t类型的字符；

### C++11中新增的char16_t和char32_t

char_16有符号，长16位；
char_32无符号，长32位；

C++11中使用前缀u表示char16_t字符常量和字符串常量；
并使用前缀U表示char32_t常量；

### bool类型

C++中一般将0解释为false，将1解释为true；

任何非零值都是true；
零值表示false；

## const限定符

C++中使用const关键字来修改变量声明和初始化；
例如：

```
const int Months = 12;
```

const限定符，限定了声明的含义；

一种常见的做法是将const限定符修饰的常量的首字母大写，表示这是一个常量；
还有一种风格是将常量的整个名称大写；

如果在定义常量的时候没有赋值，那么该常量的值是不确定的，且无法修改；

## 浮点数

C++中两种书写浮点数的方式：

1. 使用标准的小数点写法；
2. E表示法，例如：3.46E6；其中E6表示10的6次方；E表示法适合非常大的数的非常小的数；

C++中有三种浮点数：float/double/long double；

float至少32位，double至少48位，且不少于float；
long doulbe至少和double一样多；

通常float的有效位数为：32位，double的有效位数为64位，long double有效位数至少和double一样多；

上述三种类型的指数范围至少在-37,37之间；

### cout输出浮点数说明

通常cout会将浮点数小数点后的00自动删除掉，但是使用了cout.setf()之后将覆盖这种行为；
例如下列程序：

```
int main()
{
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;

    std::cout << "tub = " << tub;
    std::cout << ", a million tubs = " << million * tub;

    std::cout << ",\nand ten million tubs = ";
    std::cout << 10 * million * tub << std::endl;

    std::cout << "mint = " << mint << " and a million mints = ";
    std::cout << million * mint << std::endl;
    return 0;
}
```

上述程序对应的输出为：

```
tub = 3.333333, a million tubs = 3333333.250000,
and ten million tubs = 33333332.000000
mint = 3.333333 and a million mints = 3333333.333333
```

从上述a million tubs可以看到，由float只保留7位有效位，因此该结果在第7个3之后就失真了；

同时，对double由于其有效位为：13位，因此a million mints还是得到正确的输出的；

### 浮点常量

默认情况下，类似如下数字都是double类型的：

```
8.24
2.4E8
```

如果向指定为float类型的常量，那么在数字的后边使用f或F作为后缀即可；

对long double类型使用l或L后缀；

浮点运算的速度通常比整数慢一些，且精度将降低；

一个浮点数运算导致精度降低的例子：

```
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
```

上述程序的输出如下：

```
a = 2.34e+22
b - a = 0
```

原因：这是因为float类型的浮点数的有效位为6位或7位，那么上述的2.34e+22表示小数点左边有23位的数字，加上1之后相当于在第23位上加了1，这对a这个是用float表示的小数没有任何影响；因此最终的结果将会出现错误；

C++11中新增类型为：long long, bool, char, wchar_t；
符号整数, 无符号整数统称为整型；

C++11中新增了char16_t和char32_t；
float double long double统称为浮点型；

## C++算术运算符

/运算符为除法运算，如果两个数均为整数，那么最后结果的小数部分将被丢弃；

运算符重载是C++中的重要的OOP属性；

### 类型转换

C++有很多种类型转换：

1. 将一种算术类型的值赋值给另外一种算术类型的变量时；
2. 表达式中包含不同类型时，C++将值进行转换；
3. 将参数传递给函数时，C++将值进行转换；

例如：

```
short thirty = 30;
long l = thirty;
```

上述例子中，thirty本来应该占16位，当其被赋值给long类型的变量l时，系统自动将thirty的值30转换为32位的long类型并存储到l中，原来的thirty中对应的值30不变；

注意：当将一个很大的long值赋值给有效位数较小的float时，会出现如下情况：

```
long l = 2111222333;
float f = l;

f = 2.11122E9;
```

float为2.11122E9是因为float只有6位有效数字；

一些类型转换可能会出现的问题：

```
double -> float: 精度（有效位）降低，值可能超出目标类型的取值范围，这种情况下最终的float类型的变量的值将是不确定的；


浮点类型 -? 整型: 小数部分丢失，原来的值可能超出目标类型的取值范围，结果将是不确定的；


将较大的整型转换为较小的整型: 原来的值可能超出目标类型的取值范围，通常只复制右边的字节；

```

C++使用列表初始化时发生的转换{}

例如如下例子：

```
int x = 66;
int tmp = {x}; //是不允许的
```

上述将x使用列表初始化的方式赋值给tmp变量是不允许的，那是因为编译器不会追踪x的值的变化，同时会认为是有风险的这个操作；

### 表达式中的转换

C++中将bool char unsigned char signed char short值自动转换为int；

这些转换被称为整型提升；

代码举例：

```
short t1 = 20;
short t2 = 21;

short final = t1 + t2;
```

上述过程中，C++会自动将t1 t2转换为int类型的值，然后计算结果，最终将结果转换为目标类型short；
这是因为计算机内部int类型可能计算最快；

还存在如下的一些整型提升：

1. 如果short比int短，那么unsigned short类型将被转换为int；
2. 如果两种类型的长度相同，则unsigned short类型将被转换为unsigned int；

同时，wchar_t会被提升为，如下几个类型首先能够存储wchar_t的取值范围类型：
int, unsigned int, long, unsigned long;

当涉及到两种类型的运算时，较小的类型将会被转换为较大的类型；

有符号整型按照级别从高到低为：long long, long, int, short, signed char；
无符号整型的顺序与有符号整型相同；
类型char, signed char, unsigned char的级别相同；
类型bool的级别最低；
wchar_t, char16_t, char32_t的级别与其底层类型相同；

### 传递参数时的转换

传递参数时的类型转换通常由C++函数原型控制；

如果取消原型对参数传递的控制，C++将对char和short（signed和unsigned）类型应用整型提升；
此外，在这种情况下，C++将float参数提升为double；

### 强制类型转换

C++还允许通过强制类型转换机制进行显式类型转换；具体来说可以使用如下代码：

```
int tmp = 10;
(long) tmp;
long (tmp);
```

强制类型转换，不会修改tmp变量本身，而是创建一个新的、指定类型的值；

C++中还引入了四个强制类型转换运算符：
static_cast<>，具体使用如下：

```
static_cast<long> (tmp);
```

这种使用运算符的方式比传统的强制类型转换更严格；

### C++11中的auto声明

处理STL模板库中的复杂类型时，可以使用auto关键字；

```
std::vector<double> scores;
auto pv = scores.begin();
```


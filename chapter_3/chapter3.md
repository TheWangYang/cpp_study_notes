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

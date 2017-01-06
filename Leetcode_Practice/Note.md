# Leetcode刷题查缺补漏

###1 Two Sum

```C++
//1. vector
vector<int> result;
result.push_back(1); //末尾添加元素1
vector.begin(); //返回的是iterator,相当于地址, 可以用在sort中
vector.end();//指向尾元素的下一个位置  
//It does not point to any element, and thus shall not be dereferenced.

vector.size();      //返回元素数量

//2.sort
//需要添加
#include <algorithm>
std::sort(vector.begin, vector.begin()+20, compare);
//compare最好定义在class外, 不然比较麻烦
bool compare(int a, int b)
{
    return a<b; //升序 ascending order; a>b降序descending order
}

```

迭代器: 不只是指针. 每个标准库容器都定义了一个名为iterator的成员用来定义自己的迭代器. 它是一种比下标更通用的用法. end是一个超出容器迭代器. 
使用迭代器遍历容器: 
```C++ 
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)  //此处使用++iter而不使用iter++只是为了效率上更高
    {
        std::cout << *iter << endl;
    }
```
:: 表示调用成员 .表示调用函数

除了iterator, 每种容器还定义了const_iterator. 只能用于读取容器内元素, 不能通过解引用改变元素的值. 

vector初始化:
```C++
        vector<int> a ;                                //声明一个int型向量a
        vector<int> a(10) ;                            //声明一个初始大小为10的向量
        vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
        vector<int> b(a) ;                             //声明并用向量a初始化向量b
        vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
```

vector 子集:
```C++ 
std::vector<int> first;
std::vector<int> second;
std::vector<int> third;

first.assign (7,100);             // 7 ints with a value of 100

std::vector<int>::iterator it;
it=first.begin()+1;

second.assign (it,first.end()-1); // the 5 central values of first

int myints[] = {1776,7,4};
third.assign (myints,myints+3);   // assigning from array.
```



find用法:
1.一般用法  
InputIterator find (InputIterator first, InputIterator last, const T& val);  

first, last  
Input iterators to the initial and final positions in a sequence. The range searched is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.

val  
Value to search for in the range.
T shall be a type supporting comparisons with the elements pointed by InputIterator using operator== (with the elements as left-hand side operands, and val as right-hand side).

`if(find(result.begin(),result.end(), s[i]) != result.end())//重复了`

2. string
```C++
string str ("There are two needles in this haystack with needles.");
string str2 ("needle");
size_t found = str.find(str2);
if (found!=std::string::npos)
  std::cout << "first 'needle' found at: " << found << '\n';
```
find直接返回位置的标号(size_t类型)



### 6 Zigzag Conversion
string: 


### hash_set (unordered_set)
while(hash_set.count(s[i]))//有重复的元素 
count只返回1或者0


### 找两个有序数组的中位数
[http://bookshadow.com/weblog/2015/02/05/find-kth-smallest-element-in-the-union-of-two-sorted-arrays/]  


### 算法时间复杂度
一个算法花费的时间与算法中语句的执行次数成正比例，哪个算法中语句执行次数多，它花费时间就多。
一个算法中的语句执行次数称为语句频度或时间频度, 记为T(n)。

按数量级递增排列，常见的时间复杂度有：  
常数阶O(1),  对数阶O(log2n),  线性阶O(n),  线性对数阶O(nlog2n),  平方阶O(n^2)， 立方阶O(n^3),...， k次方阶O(n^k), 指数阶O(2^n) 。
1.O(n)，O(n^2)， 立方阶O(n^3),...， k次方阶O(n^k) 为多项式阶时间复杂度(polynominal)，分别称为一阶时间复杂度，二阶时间复杂度。。。。
2.O(2^n)，指数阶时间复杂度，该种不实用
3.对数阶O(log2n),   线性对数阶O(nlog2n)，除了常数阶以外，该种效率最高

大O表示法表示时间复杂性，注意它是某一个算法的时间复杂性。大O表示只是说有上界，由定义如果f(n)=O(n)，那显然成立f(n)=O(n^2)，它给你一个上界，但并不是上确界，但人们在表示的时候一般都习惯表示前者。


- O(1)
`Temp=i;i=j;j=temp;     `

以上三条单个语句的频度均为1，该程序段的执行时间是一个与问题规模n无关的常数。算法的时间复杂度为常数阶，记作T(n)=O(1)。如果算法的执行时间不随着问题规模n的增加而增长，即使算法中有上千条语句，其执行时间也不过是一个较大的常数。此类算法的时间复杂度是O(1)。

- O(log2n)

     i=1;       
    while (i<=n)
       i=i*2; 
解： 语句1的频度是1, 设语句2的频度是f(n),   则：2^f(n)<=n;f(n)<=log2n      
    取最大值f(n)=log2n, T(n)=O(log2n ).


1.并列循环的复杂度分析 
将各个嵌套循环的时间复杂度相加。

例如：

　　for (i=1; i<=n; i++)
　　    x++;

　　for (i=1; i<=n; i++)
　　    for (j=1; j<=n; j++)
　　        x++;

解：
第一个for循环
T(n) = n
f(n) = n
时间复杂度为Ο(n)

第二个for循环
T(n) = n2
f(n) = n2
时间复杂度为Ο(n2)

整个算法的时间复杂度为Ο(n+n2) = Ο(n2)。

### string 用法
```C++ 
//查找
str.find("ab");//返回字符串 ab 在 str 的位置
str.find("ab", 2);//在 str[2]~str[n-1] 范围内查找并返回字符串 ab 在 str 的位置
str.rfind("ab", 2);//在 str[0]~str[2] 范围内查找并返回字符串 ab 在 str 的位置


//子串
str.substr(3); //返回 [3] 及以后的子串
str.substr(2, 4); //返回 str[2]~str[2+(4-1)] 子串(即从[2]开始4个字符组成的字符串)


//插入
str.insert(2, "sz");//从 [2] 位置开始添加字符串 "sz"，并返回形成的新字符串
str.insert(2, "abcd", 3);//从 [2] 位置开始添加字符串 "abcd" 的前 3 个字符，并返回形成的新字符串
str.insert(2, "abcd", 1, 3);//从 [2] 位置开始添加字符串 "abcd" 的前 [2]~[2+(3-1)] 个字符，并返回形成的新字符串

//追加
//除了用重载的 + 操作符，还可以使用函数来完成。
str.push_back('a');//在 str 末尾添加字符'a'
str.append("abc");//在 str 末尾添加字符串"abc"

//删除
str.erase(3);//删除 [3] 及以后的字符，并返回新字符串
str.erase(3, 5);//删除从 [3] 开始的 5 个字符，并返回新字符串

//交换
str1.swap(str2);//把 str1 与 str2 交换
```






### vector<char> 转string
```c++
vector<char> temp;
string return_ = string(temp.begin(),temp.end());
```

### 递归算法的时间复杂度
[http://www.cnblogs.com/python27/archive/2011/12/09/2282486.html]

### int转char*
```C++
    int num = 100;
    char str[25];
    itoa(num, str, 10);
    printf("The number 'num' is %d and the string 'str' is %s. \n" , num, str);
```

上述函数与ANSI标准是不兼容的。能将整数转换为字符串而且与ANSI标准兼容的方法是使用sprintf()函数，请看下例：    
```C++
#include<stdio.h>  
#include <stdlib. h>

void main (void);
void main (void)
{
    int num = 100;
    char str[25];
    sprintf(str, " %d" , num);
   printf ("The number 'num' is %d and the string 'str' is %s. \n" ,
                          num, str);
}
```

在将浮点型数字转换为字符串时，需要使用另外一组函数。以下是用fcvt()函数将浮点型值转换为字符串的一个例子:  
```C++ 
# include <stdio. h>
# include <stdlib. h>
void main (void);
void main (void)
{
    double num = 12345.678;
    char * sir;
    int dec_pl, sign, ndigits = 3; /* Keep 3 digits of precision. * /
    str = fcvt(num, ndigits, &dec-pl, &sign); /* Convert the float
                                                 to a string. * /
    printf("Original number; %f\n" , num) ;  /* Print the original
                                                 floating-point
                                                    value. * /
    printf ("Converted string; %s\n",str);    /* Print the converted
                                                string's value. * /
    printf ("Decimal place: %d\n" , dec-pi) ; /* Print the location of
                                                 the decimal point. * /
    printf ("Sign: %d\n" , sign) ;            /* Print the sign.
                                                 0 = positive,
                                                 1 = negative. * /
}
```
fcvt()函数有4个参数：第一个参数是要转换的浮点型值；第二个参数是转换结果中十进制小数点右侧的位数；第三个参数是指向一个整数的指针，该整数用来返回转换结果中十进制小数点的位置；第四个参数也是指向一个整数的指针，该整数用来返回转换结果的符号(0对应于正值，1对应于负值)。



### int转string
```C++
//1.
int a = 10;
char *intStr = itoa(a);
string str = string(intStr);


//2.
int a = 10;
stringstream ss;
ss << a;
string str = ss.str();

//3.
#include <string> 

std::string s = std::to_string(42);
```

C++本身就提供了字符串与整型数之间的互换，那就是利用stringstream。下面是使用方法：
核心： 利用C++中的stringstream流。 
由于使用过程比较简单就不再赘述，直接给出示例，重要的地方在示例注释中给予说明。 

完整示例： 
```C++
#include <iostream> 
#include <string> 
#include <sstream>      //要使用stringstream流应包含此头文件 
using namespace std; 

int main() 
{ 
stringstream stream;     //声明一个stringstream变量 
int n; 
string str; 

//string转int 
stream << "1234";     //向stream中插入字符串"1234" 
stream >> n;     //从stream中提取刚插入的字符串"1234"  并将其赋予变量n完成字符串到int的转换 
cout << n << endl;     //输出n 

stream.clear();     //同一stream进行多次转换应调用成员函数clear 

//int转string 
stream << 1234;     //向stream中插入整型数1234 
stream >> str;     //从steam中提取刚插入的整型数   并将其赋予变量str完成整型数到string的转换 
cout << str << endl;     //输出str 
return 0; 
} 
```

### std::min_element / std::max_element
```c++
  int main () {
  int myints[] = {3,7,2,5,6,4,9};

  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

}
```
template <class ForwardIterator>
  ForwardIterator max_element (ForwardIterator first, ForwardIterator last);
包括first,不包括last

### void *指针
指针有两个属性:指向变量/对象的地址和长度 
但是指针只存储地址,长度则取决于指针的类型 
编译器根据指针的类型从指针指向的地址向后寻址 
指针类型不同则寻址范围也不同,比如:   
int*从指定地址向后寻找4字节作为变量的存储单元 
double*从指定地址向后寻找8字节作为变量的存储单元 

1.void指针是一种特别的指针 
   void *vp 
   //说它特别是因为它没有类型 
   //或者说这个类型不能判断出指向对象的长度 

2.任何指针都可以赋值给void指针 
   type *p; 
   vp=p; 
   //不需转换 
   //只获得变量/对象地址而不获得大小 

3.void指针赋值给其他类型的指针时都要进行转换 
   type *p=(type*)vp; 
   //转换类型也就是获得指向变量/对象大小 
转:http://icoding.spaces.live.com/blog/cns!209684E38D520BA6!130.entry 

4.void指针不能复引用 
   *vp//错误 
   因为void指针只知道,指向变量/对象的起始地址 
   而不知道指向变量/对象的大小(占几个字节)所以无法正确引用 

5.void指针不能参与指针运算,除非进行转换 
   (type*)vp++; 
   //vp==vp+sizeof(type)


### NULL 和 nullptr
在C语言中，NULL通常被定义为如下：
```C
 #define NULL ((void *)0) 
```

而如果换做一个C++编译器来编译的话是要出错的，因为C++是强类型的，void *是不能隐式转换成其他指针类型的. 而又为了解决空指针的问题，所以C++中引入0来表示空指针. NULL就被直接定义为一个整型 0。  在大多数情况下这并不会产生什么问题，但是万一有重载或者模板推导的时候，编译器就无法给出正确结果了。比如下面的情形：
```C++
void call_back_process(CCObject* target, void* data);  
bind(call_back_process, target, NULL);   // error 函数类型是void* 但是我们绑定的是一个整型 0  
```
如果我们的编译器是支持nullptr的话，那么我们应该直接使用nullptr来替代NULL的宏定义。正常使用过程中他们是完全等价的。







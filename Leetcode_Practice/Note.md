# Leetcode刷题查缺补漏

###1 Two Sum

```c++
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
```c++ 
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)  //此处使用++iter而不使用iter++只是为了效率上更高
    {
        std::cout << *iter << endl;
    }
```
:: 表示调用成员 .表示调用函数

除了iterator, 每种容器还定义了const_iterator. 只能用于读取容器内元素, 不能通过解引用改变元素的值. 

vector初始化:
```c++
        vector<int> a ;                                //声明一个int型向量a
        vector<int> a(10) ;                            //声明一个初始大小为10的向量
        vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
        vector<int> b(a) ;                             //声明并用向量a初始化向量b
        vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
```

vector 子集:
```c++ 
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
注意algorithm中的find的时间复杂度是O(n).  
1.一般用法  
InputIterator find (InputIterator first, InputIterator last, const T& val);  

first, last  
Input iterators to the initial and final positions in a sequence. The range searched is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.

val  
Value to search for in the range.
T shall be a type supporting comparisons with the elements pointed by InputIterator using operator== (with the elements as left-hand side operands, and val as right-hand side).

`if(find(result.begin(),result.end(), s[i]) != result.end())//重复了`

2. string
```c++
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
```c++ 
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
```c++
    int num = 100;
    char str[25];
    itoa(num, str, 10);
    printf("The number 'num' is %d and the string 'str' is %s. \n" , num, str);
```

上述函数与ANSI标准是不兼容的。能将整数转换为字符串而且与ANSI标准兼容的方法是使用sprintf()函数，请看下例：    
```c++
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
```c++ 
# include <stdio. h>
# include <stdlib. h>
void main (void);
void main (void)
{
    double num = 12345.678;
    char * sir;
    int dec_pl, sign, ndigits = 3; // Keep 3 digits of precision. * /*/
    str = fcvt(num, ndigits, &dec-pl, &sign); // Convert the float to a string. * /
    printf("Original number; %f\n" , num) ;  // Print the original floating-point value. * /
    printf ("Converted string; %s\n",str);    // Print the converted  string's value. * /
    printf ("Decimal place: %d\n" , dec-pi) ; /* Print the location of the decimal point. */
    printf ("Sign: %d\n" , sign) ;            // Print the sign.
                                              //   0 = positive,
                                                 1 = negative. 
}
```

fcvt()函数有4个参数：第一个参数是要转换的浮点型值；第二个参数是转换结果中十进制小数点右侧的位数；第三个参数是指向一个整数的指针，该整数用来返回转换结果中十进制小数点的位置；第四个参数也是指向一个整数的指针，该整数用来返回转换结果的符号(0对应于正值，1对应于负值)。



### int转string
```c++
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
```c++
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
```c
 #define NULL ((void *)0) 
```

而如果换做一个C++编译器来编译的话是要出错的，因为C++是强类型的，void *是不能隐式转换成其他指针类型的. 而又为了解决空指针的问题，所以C++中引入0来表示空指针. NULL就被直接定义为一个整型 0。  在大多数情况下这并不会产生什么问题，但是万一有重载或者模板推导的时候，编译器就无法给出正确结果了。比如下面的情形：
```c++
void call_back_process(CCObject* target, void* data);  
bind(call_back_process, target, NULL);   // error 函数类型是void* 但是我们绑定的是一个整型 0  
```
如果我们的编译器是支持nullptr的话，那么我们应该直接使用nullptr来替代NULL的宏定义。正常使用过程中他们是完全等价的。


### queue 和 stack
queue队列: 先进先出  
<queue> 支持: empty(),size(), front()返回最头部的元素(最先进入的元素), back()返回最尾部的元素(最后进入的元素), push(), pop()  
stack: 后进先出
<stack> 支持: empty(),size(), top()最顶部的元素(最后进入的元素), push(), pop()


### 二维vector遍历
```c++
for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for(vector<int>::iterator it2 = (*it).begin(); it2!= (*it).end();++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
```


### hash_set 和 hash_map
set就是数的集合, 可以以O(1)的效率查找和添加. map是一个key和value对应的集合,类似{('j', "faefa"),('a', "asfasece"),...}

### C++ istringstream, ostringstream, stringstream
需要头文件<sstream>.  
istringstream，由 istream 派生而来，提供读 string 的功能。
ostringstream，由 ostream 派生而来，提供写 string 的功能。
stringstream，由 iostream 派生而来，提供读写 string 的功能。

1. stringstream
```c++
stringstream strm; // 创建自由的 stringstream 对象  
stringstream strm(s); //创建存储 s 的副本的 stringstream 对象，其中 s 是 string 类型的对象 
strm.str()  //返回 strm 中存储的 string 类型对象  
strm.str(s)  //将 string 类型的 s 复制给 strm，返回 void
```

有些程序需要两种处理: 有些处理基于每行实现，而其他处理则要操纵每行中每个单词。可用 stringstreams 对象实现：
```c++
string line, word;      // will hold a line and word from input,respectively
while (getline(cin, line))  // read a line from theinput into line (do per-line processing )    
{     
    istringstream stream(line);  // bind to stream to the line we read      
    while (stream >> word)     
    {  
      // read a word from line          
      // do per-word processing     
    } 
} 
```

2. ostringstream
ostringstream 对象用来进行格式化的输出，可以方便的将各种类型转换为string类型  
ostringstream 只支持 << 操作符

ostringstream对象的一个常见用法是，需要在多种数据类型之间实现自动格式化时使用该类类型。例如，有一个数值型数据集合，要获取它们的 string 表示形式，或反之。sstream 输入和输出操作可自动地把算术类型转化为相应的 string 表示形式，反过来也可以
```c++
int val1 = 512, val2 = 1024; 
ostringstream format_message; 
 // ok: converts values to a string representation  
format_message << "val1: " << val1 << "\n"<< "val2: " << val2 << "\n";

```
format_message 的内容是以下字符：val1: 512\nval2: 1024  



3. istringstream

相反，用 istringstream 读 string 对象，即可重新将数值型数据找回来. 读取istringstream对象自动地将数值型数据的字符表示方式转换为相应的算术值
```c++
// str member obtains the string associated with a stringstream 
istringstream input_istring(format_message.str()); 
string dump; // place to dump the labels from the formatted message 
// extracts the stored ascii values, converting back to arithmetic types 
input_istring >> dump >> val1 >> dump >> val2;  
cout << val1 << " " << val2 << endl;  
// prints 512 1024
```
format_message.str()成员获取与之前创建的 ostringstream 对象关联的 string 副本. 再将 input_istring 与 string 绑定起来。在读 input_istring 时，相应的值恢复为它们原来的数值型表示形式为了读取input_string，必须把该 string 对象分解为若干个部分。我们要的是数值型数据；为了得到它们，必须读取（和忽略）处于所需数据周围的标号. 

因为输入操作符读取的是有类型的值，因此读入的对象类型必须和由 stringstream 读入的值的类型一致。在本例中，input_istring 分成四个部分：  string 类型的值 val1，接着是 512，然后是 string 类型的值 val2，最后是 1024。一般情况下，使用输入操作符读 string 时，空白符将会忽略。于是，在读与 format_message 关联的 string 时，忽略其中的换行符



### string.find_last_of(char)
Searches the string for the last character that matches any of the characters specified in its arguments. Returns the position.  
Note: The first character is denoted by a value of 0 (not 1).

### C++ auto关键字
根据初始化表达式自动推断被声明的变量的类型，如：
```c++ 
 auto f=3.14;      //double
 auto s("hello");  //const char*
 auto z = new auto(9); // int*
 auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
```
但是，这么简单的变量声明类型，不建议用auto关键字，而是应更清晰地直接写出其类型。  
auto关键字更适用于类型冗长复杂、变量使用范围专一时，使程序更清晰易读
```c++
std::vector<int> vect; 
 for(auto it = vect.begin(); it != vect.end(); ++it)
 {  //it的类型是std::vector<int>::iterator
    std::cin >> *it;
  }

```

在模板函数定义时，如果变量的类型依赖于模板参数，使用auto关键字使得在编译期确定这些类型，如：
```c++
 template <class T, class U>
 void Multiply(T t, U u)
 {
      auto v = t * u;
      std::cout<<v;
 }
 ```

### string::npos
`static const size_t npos = -1;   //definition`  
Maximum value for size_t  
npos is a static member constant value with the greatest possible value for an element of type size_t.  
This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".  
As a return value, it is usually used to indicate no matches.



### inline function
 Inline function is introduced which is an optimization technique used by the compilers especially to reduce the execution time. 类似C中的Macro.
 內联（inline）指的是在使用函数的地方不进行函数调用，而是将函数的实现代码插入到此处。 这样能够以增加代码大小为代价，省下函数调用过程产生的开销，加快程序执行速度。 內联属于编译器的一个优化措施，而inline关键字就是用来告诉编译器，希望对指定的函数做內联优化。   
 相比C中的宏定义, 它有类型检查, 使用更加安全. 

  Sometimes not useful for example in __embedded system__ where large executable size is not preferred at all due to memory constraints.


### 完全二叉树 二叉堆
把完全二叉树(排列紧凑)按照level order顺序可以放在数组中. 那么对于任意一个根节点i(从0开始), 它的子节点分别对应数组中的(2*i+1) 和 (2*i+2).

### priority_queue
Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.

This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

### instantiation
In object-oriented programming (OOP), an instance is a concrete occurrence of any object, existing usually during the runtime of a computer program. Formally, "instance" is synonymous with "object" as they are each a particular value (realization), and these may be called an instance object; "instance" emphasizes the distinct identity of the object. The creation of an instance is called instantiation.


### Encapsulation
A language mechanism for restricting direct access to some of the object's components.

A language construct that facilitates(促进 帮助) the bundling of data with the methods (or other functions) operating on that data. 

### Multiple inheritance
指的是一个类别可以同时从多于一个父类继承行为与特征的功能。与单一继承相对，单一继承指一个类别只可以继承自一个父类。

### override & overload
方法的重写(Overriding)和重载(Overloading)是Java多态性的不同表现。重写(Overriding)是父类与子类之间多态性的一种表现，而重载(Overloading)是一个类中多态性的一种表现。  
如果在子类中定义某方法与其父类有相同的名称和参数，我们说该方法被重写 (Overriding)。子类的对象使用这个方法时，将调用子类中的定义，对它而言，父类中的定义如同被"屏蔽"了。   
如果在一个类中定义了多个同名的方法，它们或有不同的参数个数或有不同的参数类型或有不同的参数次序，则称为方法的重载(Overloading)。不能通过访问权限、返回类型、抛出的异常进行重载.


### polymorphism 多态
C++多态性是通过虚函数来实现的，虚函数允许子类重新定义成员函数，而子类重新定义父类的做法称为覆盖(override)，或者称为重写。用于接口重用(interface)


### sort排序 主要是merge sort(归并排序), quick sort(快速排序), heap sort(堆排序)
1. merge sort
时间复杂度O(n*logn).

2. quick sort
平均O(n*logn), 最坏O(n^2), 但不常见. 为了避免最坏情况, 可以引入随机算法, 随机选取pivot轴心. 

3. 

### 
reverse: `std::reverse(result.begin(), result.end());` <algorithm>
max/min:
swap: 
find_last_of:


### Binary Tree
- Binary Search Tree: 二叉查找树（英语：Binary Search Tree），也称二叉搜索树、有序二叉树（英语：ordered binary tree），排序二叉树（英语：sorted binary tree），是指一棵空树或者具有下列性质的二叉树:
  - 若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
  - 若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
  - 任意节点的左、右子树也分别为二叉查找树；
  - 没有键值相等的节点。


- Balanced Binary Tree: A balanced binary tree has the minimum possible maximum height (a.k.a. depth) for the leaf nodes.
One common balanced tree structure is a binary tree structure in which the left and right subtrees of every node differ in height by no more than 1.

- Self-balancing Binary Search Tree(AVL Tree): 自平衡二叉树.一般的二叉查找树的查询复杂度是跟目标结点到树根的距离（即深度）有关，因此当结点的深度普遍较大时，查询的均摊复杂度会上升，为了更高效的查询，平衡树应运而生.它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。An AVL tree (Georgy Adelson-Velsky and Evgenii Landis' tree, named after the inventors) is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; If at any time they differ by more than one, rebalancing is done to restore this property. 

- Complete Binary Tree: In a complete binary tree, every level except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.



### cbegin, cend()
A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by unordered_map::begin, but it cannot be used to modify the contents it points to.
只能用于循环 不能用于修改.

### unordered_map中的key和value的对应
Iterators to elements of unordered_map containers access to both the key and the mapped value. For this, the class defines what is called its value_type, which is a pair class with its first value corresponding to the const version of the key type (template parameter Key) and its second value corresponding to the mapped value (template parameter T):  
`typedef pair<const Key, T> value_type;`

Iterators of a unordered_map container point to elements of this value_type. Thus, for an iterator called it that points to an element of a map, its key and mapped value can be accessed respectively with:
```c++
unordered_map<Key,T>::iterator it;
(*it).first;             // the key value (of type Key)
(*it).second;            // the mapped value (of type T)
(*it);                   // the "element value" (of type pair<const Key,T>)
```

Naturally, any other direct access operator, such as -> or [] can be used, for example:
```c++
it->first;               // same as (*it).first   (the key value)
it->second;              // same as (*it).second  (the mapped value) 
```
指针class用`->`, 对象class用`.`


`unordered_map::find()`Searches the container for an element with k as key and returns an `iterator` to it if found, otherwise it returns an `iterator` to unordered_map::end (the element past the end of the container).


### pair
`#inlcude <utility>`
- 概述:  
pair是一种模板类型，其中包含两个数据值，两个数据的类型可以不同，基本的定义如下：
 
`pair<int, string> a;`

表示a中有两个类型，第一个元素是int型的，第二个元素是string类型的，如果创建pair的时候没有对其进行初始化，则调用默认构造函数对其初始化。
 
`pair<string, string> a("James", "Joy");`
也可以像上面一样在定义的时候直接对其初始化。
 
由于pair类型的使用比较繁琐，因为如果要定义多个形同的pair类型的时候，可以时候typedef简化声明：
typedef pair<string, string> author;
author pro("May", "Lily");
author joye("James", "Joyce");

- pair对象的操作:
1. 对于pair类，由于它只有两个元素，分别名为first和second，因此直接使用普通的点操作符即可访问其成员
```c++
pair<string, string> a("Lily", "Poly"); 
string name;
name = a.second;
```

2. 生成新的pair对象:  
可以使用make_pair对已存在的两个数据构造一个新的pair类型：
```c++
int a = 8;
string m = "James";
pair<int, string> newone;
newone = make_pair(a, m);
```

### sort
sort可以用于string, 默认按照从a到z

### to_string
```c++
string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);
```
Returns a string with the representation of val.

### pow
c++中指数不能用`^`, 要用`pow(底数,指数)`表示.


### split
```c++
  #include <boost/algorithm/string.hpp> //must have
  string s = "a,b, c ,,e,f,";
  vector <string> fields;

  cout << "Original = \"" << s << "\"\n\n";

  cout << "Split on \',\' only\n";
  split( fields, s, is_any_of( "," ) );
  print( fields );

```

or
```c++
int main()
{
    string str("Split me by whitespaces");
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream
    
    vector<string> tokens; // Create vector to hold our words
    
    while (ss >> buf)
        tokens.push_back(buf);
    
    for(auto it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
}
```
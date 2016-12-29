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
find用法:  
`if(find(result.begin(),result.end(), s[i]) != result.end())//重复了`

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



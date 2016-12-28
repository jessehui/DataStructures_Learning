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


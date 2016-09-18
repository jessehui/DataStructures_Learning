# Data Structures and Algorithm Notes
> Basic

### 数组和链表
数组优劣: 易于查找引用元素, 但是不容易插入删除元素.   
链表: 易于插入删除元素. 查找比较麻烦, 用循环一个一个next找.
```C++
struct node{
    int payload;
    node* next;
};
```

`node *head = nullptr;` nullptr表示空指针.
```C++
int* p1 = 0;  //ok
int* p2 = nullptr;  //ok

int n1 = 0;             // ok  
int n2 = nullptr;       // error 
```
reference: [http://blog.csdn.net/huang_xw/article/details/8764346]

### new 和 malloc
`long *pNumber = (long*)malloc(sizeof(long) * 1000000); //c `  
`long* pNumber = new long[1000000]; //c++`  


### 数组倒序排列
要让数组倒序只要交换最左边和最右边的元素, 然后交换次左边和次右边的元素. 然后持续, 直到遍历了所有元素(偶数个元素), 或者剩下唯一一个元素(奇数个元素), 这样整个数组就被倒序排列了. 

并不是所有指令都和数据量的增长有关系.   O(n)增长是线性的. 下表时间复杂度从上到下增加.

|O(1) | 常数阶 |
|-------|------|
|O(log n)| 对数 |
|--------|------|
|O((log n)^C) | 多对数 |
|-------|------|
|O(n)| 线性 |
|--------|------|
|O(n log * n) | 迭代对数 |
|-------|------|
|O(n log n)| 线性对数 |
|--------|------|
|O(n^2) | 平方 |
|-------|------|
|O(n^c)| 多项式 |
|--------|------|
|O(c^n)| 指数 |
|--------|------|
|O(n!) | 阶乘 |
|-------|------|


一实数的迭代对数是指需对实数连续进行几次对数运算后，其结果才会小于等于1。  
关于递归算法的时间复杂度. 例如斐波那契数列的时间复杂度为O(2^n).

利用递归算法reverse链表:
```C++
node* reverse_recursive(node *head)
{
    if(head == nullptr || head->next == nullptr)
    return head;
    node* second = head->next;
    node* new_head = reverse_recursive(second);
    second->next = head;
    head->next = nullptr;
    return new_head;

}
```
时间复杂度计算: 
T(0) = O(1);  
T(1) = O(1);  
T(n) = T(n-1) + O(1);  
     = T(n-2) + O(1) + O(1);  
     = T(n-3) + O(1) + O(1);  
     = n*O(1);  
     = O(n);    

this指针:  
`node(int payload) {this->payload = payload;};`  
1. this指针是一个隐含于每一个成员函数中的特殊指针。它指向正在被该成员函数操作的那个对象。
2. 当对一个对象调用成员函数时，编译程序先将对象的地址赋给this指针，然后调用成员函数，每次成员函数存取数据成员时，由隐含使用this指针。
3. 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。 
4. 在C++中，this指针被隐含地声明为: X *const this,这意味着不能给this 指针赋值；
   在X类的const成员函数中，this指针的类型为：const X* const, 这说明this指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）; 
5. 由于this并不是一个常规变量，所以，不能取得this的地址。

关于C++的类中 private, public, protected:  


















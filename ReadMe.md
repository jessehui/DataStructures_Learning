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
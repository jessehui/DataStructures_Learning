//
//  test_heap.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/21/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <vector>   //用数组实现一个堆
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class binary_heap{
    
    vector<T> vec;
    
protected:  //可以被派生类对象访问 不能被用户代码访问
    virtual bool compare(int a, int b) = 0; //函数=0表明是纯虚函数 必须使用重载函数(overloaded function)

public: //可以被用户代码访问
    void insert(T val)
    {
        vec.push_back(val); //先放入数组中
        int pos = vec.size() - 1;   //得到新加节点的位置
        while(pos >= 0)
        {
            int parent = (pos-1)/2;
            if(parent < 0 || !compare(val, parent)) //val > parent 时返回true 所以这里是如果val < parent 进入 if
                break;  //val < parent表示已经达到了最大堆的规则 可以结束了
            
            //如果没有进入if
            swap(vec[pos],vec[parent]);
            pos = parent;
        }
    }
    
    int size()
    {
        return vec.size();
    }
    
    bool empty()
    {
        return vec.empty();
    }
    
    void delete_root()
    {
        vec[0] = vec.back();
        vec.pop();
        heapify(0);
    }
    
    void dump() //print all val
    {
        for(auto it = vec.begin(); it != vec.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    
    T root()
    {
        return vec[0];
    }
    
    
private:
    void heapify(int pos)
    {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int largest_pos = pos;    //init
        
        //找到三个中的最大值
        if(left < vec.size() && compare(vec[left],vec[largest_pos]))
            largest_pos = left;
        if(right < vec.size() && compare(vec[left], vec[largest_pos]))
            largest_pos = right;
        
        //把最大值放在堆顶, 然后对下边递归heapify
        if(largest_pos != pos)
        {
            swap(vec[largest_pos], vec[pos]);
            heapify(largest_pos);
        }
        
        
    }
    



};

template <typename T>
class max_binary_heap: public binary_heap<T>{

virtual bool compare(int a, int b)
{
    return a > b;   //max binary heap
}
};


template <typename T>
class min_binary_heap: public binary_heap<T>{

    virtual bool compare(int a , int b)
    {
        return a < b;
    }

};

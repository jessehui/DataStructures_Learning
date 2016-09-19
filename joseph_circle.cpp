//
//  joseph_circle.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/17/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
    int payload;
    node *next;
    node(int payload) {this->payload = payload;};   //定义时可以直接传初值 类似类中的构造函数
};

class joseph_circle
{
    node *tail;
    node *eliminate_ptr;
    
public:
    joseph_circle() {tail = nullptr;}   //定义时就直接赋值
    
    //add a new node to joseph circle
    void add(int value)
    {
        //1. it is empty
        if(tail == nullptr)
        {
            tail = new node(value);
            tail->next = tail;  //现在只有一个元素 所以只能指向它自己
        }
        //2. not empty, then insert new node at the end of the circle
        else
        {
            node *new_node = new node(value);
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;    //新加的节点在末尾
            
        }
        
    }
    
    void eliminate(int step)    //数到几的时候删除此节点
    {
        node *p = tail;
        while( p != nullptr && p->next != p )//不为空 且不能只有本身一个元素
        {
            for(int i = 0; i < step - 1; i++)       //要在step的之前一个停下来更改节点的连接方式
                p = p->next;    //前进到step之前一个节点的位置
        
        node *eliminate_node = p->next; //到达要删除的节点
        p->next = p->next->next;    //跨过要删除的节点
        
        //这个时候 普通情况下已经删除完了 但是当要删除的节点是tail的时候记得更新tail
        if(eliminate_node == tail)
            tail = p;
        
        cout << "eliminating node : " << eliminate_node->payload << endl;
        
        delete eliminate_node;  //free mem
        output();
        }
        
        
    }
    
    //遍历 打印所有节点
    void output()
    {
        node *p = tail;
        while(p != nullptr)
        {
            //先从第一个元素开始打印
            p = p->next;
            cout << p->payload << " ";
            
            if(p == tail)   //回到tail说明已经遍历完了
                break;
        }
        cout << endl;
    }
    
    
    
    
    
};



int main()
{
    cout << "Run" << endl;
    joseph_circle joseph_test;
    
    //insert 6 nodes
    for(int i = 0;i < 6;i++)
        joseph_test.add(i);
    
    joseph_test.eliminate(3);
    return 0;
}











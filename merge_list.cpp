//
//  merge_list.cpp
//  datastucture_test
//
//  Created by Jesse. on 10/1/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
    int payload;
    node* next;
    node(int payload) {this->payload = payload; this->next = nullptr;};
    
    
};

class linked_list{
    node *head, *tail;
    
public:
    //constructor, intialize head, tail to nullptr
    linked_list() : head(nullptr), tail(nullptr) {};
    
    //push a new node at the end of the list 用于构建新的list
    void push_back(int value)
    {
        if(empty())
        {
            head = tail = new node(value);
        }
        else
        {
            tail->next = new node(value);
            tail = tail->next;
        }
    }
    
    //return the value stored in the first node 用于merge时比较
    int front()
    {
        if(empty())
            throw"this list is empty";  //出错处理
        return head->payload;
    }
    
    //remove the first node 用于更新老的list
    void pop_front()
    {
        if(empty())
            throw "this list is empty";
        node *first_node = head;
        head = head->next;
        delete first_node;
        
    }
    
    bool empty()
    {
        return head == nullptr;
    }
    
    void output()
    {
        node *iterator = head;
        while(iterator)
        {
            cout << iterator->payload << "";
            iterator = iterator->next;
        }
        cout << endl;
    }
    
    
    
};


//merge two sorted linked list return a new list
linked_list merge(linked_list a, linked_list b)
{
    linked_list result;
    while(!a.empty() || !b.empty())//任意一个为非空
    //(因为两个list都在不断更新, 直到两个list都为空了则说明元素都放在新的list里了)
    {
        if(a.empty())
        {
            result.push_back(b.front());
            b.pop_front();
        }
        else if(b.empty())
        {
            result.push_back(a.front());
            a.pop_front();
        }
        else if(a.front()>b.front())
        {
            result.push_back(b.front());    //先放小数
            b.pop_front();
        }
        else
        {
            result.push_back(a.front());
            a.pop_front();
        }
    }
    return result;
}

int main()
{
    linked_list a,b;
    
    linked_list result = merge(a, b);
    result.output();
    return 0;
}













//
//  test_stack.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/9/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>   //node<T>就是一种template的类型
struct node{
    T payload;
    node *next;
    node(T payload) {this->payload = payload;}; //两种构造函数方法: (1)
    //可以不定义next指向 而在每次初始化的时候单独指明
};



template <typename T>
class stack{
    node<T> *head;
    
public:
    stack(): head(nullptr){};   //(2)
  
    bool empty()
    {
        return head == nullptr;
    }
    
    
    void push(T value)  //压栈 head指向栈顶
    {
        node<T> *new_node = new node<T>(value);
        new_node -> next = head;
        head = new_node;
    }
    
    void pop()
    {
        if(empty())
            throw "It is empty.";
        
        node<T> *temp = head;
        head = head->next;  //把head指向下一个元素
        delete temp;
    }
    
    T top()
    {
        if(empty())
            throw "It is empty.";
            
        return head->payload;
    }
    

};

//这就是一个经典的栈匹配。一个栈，左符号入栈，右符号出栈。最后检查栈是否为空。

bool isValid2(string s) {
   
    size_t length = s.length();
    if(length == 0)
        return true;
    
    vector<char> stack;
    
    for(int i = 0;i < length; i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            stack.push_back(s[i]);
        }
        
        else
            if(stack.size() != 0 && stack.back() == '{' && s[i] == '}')
            {
                cout << "stack.back() =" << stack.back();
                stack.pop_back();
            }
        else
            if(stack.size() != 0 && stack.back() == '[' && s[i] == ']')
                stack.pop_back();
        else
            if(stack.size() != 0 && stack.back() == '(' && s[i] == ')')
                stack.pop_back();
        
        else return false;  //如果每一个case都不是, 那就是单独的右半边符号, 一定是invalid 直接return
    }
    
    cout << "Final size = " << stack.size() << endl;
    
    
    if(stack.size() == 0)
        return true;
    else return false;
    
}

//用自己的栈实现一下
bool isValid(string s) {
    
    size_t length = s.length();
    if(length == 0)
        return true;
    
    stack<char> stack_test;
    
    for(int i = 0;i < length; i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            stack_test.push(s[i]);
        }
        
        else
            if(stack_test.empty() != true && stack_test.top() == '{' && s[i] == '}')
            {
                cout << "stack.back() =" << stack_test.top();
                stack_test.pop();
            }
            else
                if(stack_test.empty() != true &&  stack_test.top() == '[' && s[i] == ']')
                     stack_test.pop();
                else
                    if(stack_test.empty() != true &&  stack_test.top() == '(' && s[i] == ')')
                         stack_test.pop();
        
                    else return false;  //如果每一个case都不是, 那就是单独的右半边符号, 一定是invalid 直接return
    }
    
//    cout << "Final size = " << stack.size() << endl;
    
    
    if(stack_test.empty())
        return true;
    else return false;
    
}

int main()
{
    string s = "({}{}{}{}{}[])";
    bool result = isValid(s);
    cout << "It is " << result << endl;
    return 0;
}



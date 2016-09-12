//
//  linked_list_reverse.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/11/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int payload;
    node *next;
};

node * reverse_recursive(node *head)    //递归方法 返回新的头
{
    if(head == nullptr || head->next == nullptr)
        return head;
    node *second = head->next;  //old second
    node *new_head = reverse_recursive(second);
    second->next = head;    //一旦有返回了, 就可以开始下一个
    head->next = nullptr;
    return new_head;
}

int main()
{
    node *head = nullptr;
    for(int i = 0; i < 10; i++)
    {
        node *new_node = new node;
        new_node->next = head;
        new_node->payload = i*10;
        head = new_node;
    }
    
    head = reverse_recursive(head); //把head重新放到最初的位置
    
    node *iterator = head;
    while(iterator)
    {
        cout << iterator->payload <<endl;
        iterator = iterator->next;
    }
    
    return 0;
}

//
//  remove_nth_node.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/5/17.
//  Copyright © 2017 Jesse. All rights reserved.
////
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
#include <stdio.h>
#include <iostream>

using namespace std;

////c中的写法
//typedef struct Node{
//    int payload;
//    struct Node* next;  //因为刚开始初始化的时候还不知道Node的类型
//}node;
////这样在初始化的时候可以用
//node node1;
////如果不加typedef
//struct Node_{
//    int payload;
//    struct Node_* next;
//};
//struct Node_ node2; //就要一直带着struct


//C++中 不需要typedef
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}  //初始化函数
};

// ListNode node1;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head->next == nullptr)
        return nullptr;
    
    int length = 1;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;     //如果除去的是head
    
    while(head->next != nullptr)
    {
        head = head->next;
        length ++ ;
    }
    cout << "length = " << length << endl;

    head = dummy->next;
    if(length == n)//去掉head
    {
        head = head->next;
        return head;
    }
        
    for(int i = 0; i < length - n - 1; i++)
    {
        head = head->next;
    }
    
    head->next = head->next->next;
    
    return dummy->next;
}

void print_list(ListNode *head)
{
    cout << head->val << " -> " ;
    while(head->next != nullptr)
    {
        head = head->next;
        cout << head->val << " -> " ;
    }
    cout << "nullptr" << endl;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    //头插法
    ListNode *head2 = nullptr;
 //  ListNode *node2 = new ListNode(i);
 //   node2->next = head;
    for(int i = 0; i < 5 ; i ++)
    {
        ListNode *node2 = new ListNode(i);
        node2->next = head2;
        head2= node2;
    }
    cout << "definition end" << endl;
    print_list(head2);
    
    return 0;
    
    
    //尾插法
    for(int i = 1; i < 5 ; i++)
    {
        ListNode *node = new ListNode(i);
        head->next = node;
        head = node;
    }
    head = temp;
    print_list(head);
    head = removeNthFromEnd(head, 5);
    print_list(head);
    
    return 0;
}

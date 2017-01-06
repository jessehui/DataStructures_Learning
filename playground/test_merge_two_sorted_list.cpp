//
//  remove_nth_node.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/5/17.
//  Copyright © 2017 Jesse. All rights reserved.
////
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together
//the nodes of the first two lists.
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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while(l1 != nullptr || l2 != nullptr)//while直到两个都为空
    {
        if(l1 == nullptr)
        {
            head->next = l2;
            break;
        }
        else
            if(l2 == nullptr)
            {
                head -> next = l1;
                break;
            }
        
        if(l1->val < l2->val)
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        print_list(temp->next);
    }
    cout << endl;
    print_list(temp->next);
    return temp->next;;
    
        
    
}











int main()
{
    
    ListNode *head2 = new ListNode(1);
    ListNode *temp2 = head2;
    
    for(int i = 1; i < 5 ; i++)
    {
        ListNode *node2 = new ListNode(2*i+1);
        head2->next = node2;
        head2 = node2;
    }
    head2 = temp2;
    print_list(head2);//1 3 5 7 9
    
    //尾插法
    ListNode *head = new ListNode(0);
    ListNode *temp = head;

    for(int i = 1; i < 5 ; i++)
    {
        ListNode *node = new ListNode(2*i);
        head->next = node;
        head = node;
    }
    head = temp;
    print_list(head);   //0 2 4 6 8
    cout << endl;
    mergeTwoLists(head, head2);
    
    return 0;
}

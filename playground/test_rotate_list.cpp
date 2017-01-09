//
//  test_rotate_list.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/8/17.
//  Copyright © 2017 Jesse. All rights reserved.
//
//Given a list, rotate the list to the right by k places, where k is non-negative.

//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

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

//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

ListNode* rotateRight(ListNode* head, int k) {
    
    if(k==0 || head == nullptr || head->next == nullptr )
        return head;
    
    
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int length = 0;
    
    while( head!= nullptr )
    {
        length++;
        head = head->next;
    }
    
    head = dummy->next;
    
    cout << " length = " << length;
    if(k >= length)
    {
        k = k%length;
        if( k == 0 )
            return head;
    }
    
    cout << "  ; k = " << k << endl;
    
    
    for(int i = 0; i < length - k - 1 ;i++)  //到达 把对应的next设为nullptr
    {
        head = head->next;
    }
    
    cout << "val = " << head->val << endl;

    //获得需要rotate的头地址
    ListNode *rotate = head->next;
    
    //把后边的尾巴斩断
    head->next = nullptr;
    
    //开始连接
    head = rotate;
    while(rotate->next != nullptr)
    {
        rotate = rotate->next;
    }
    
    //到达需要拼接的位置
    rotate->next = dummy->next;
    
    return head;
    
    
    
}


ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* new_dummy = dummy;
    
    ListNode* head2 = head->next;
    ListNode* new_head = head2->next;
    
    head2->next = head;
    head->next = new_head;
    dummy->next = head2;
    
    print_list(dummy->next);
    cout << endl;
    
    if(head->next == nullptr)   //这个时候已经调换位置了, 最后一个数是head
        return dummy->next;
    
    for(int i = 0; i < 3; i++)//set the position of head2
        head2 = head2->next;
    
    new_dummy = head;
    head = new_head;    // set the position of head1
    
    while(head2 != nullptr)
    {
        
        new_head = head2->next;
        
        
        //swap
        head2->next = head;
        head->next = new_head;
        new_dummy->next = head2;
        
        print_list(dummy->next);
        
        if(head->next == nullptr)   //这个时候已经调换位置了, 最后一个数是head
            break;
        
        for(int i = 0; i < 3; i++)//set the position of head2
        {
            cout << "(i = " << i << ")  " ;
        
            head2 = head2->next;
        }
        
        cout << endl;
        new_dummy = head;   //set the position of new dummy
        
        head = new_head;    // set the position of head1
        
       
        print_list(dummy->next);
        cout << endl;
    }
    
    return dummy->next;
}







int main()
{
    
    ListNode *head2 = new ListNode(1);
    ListNode *temp2 = head2;
    
    for(int i = 1; i < 2 ; i++)
    {
        ListNode *node2 = new ListNode(2*i+1);
        head2->next = node2;
        head2 = node2;
    }
    head2 = temp2;
//    print_list(head2);//1 3 5 7 9
    
    swapPairs(head2);
    
    
    return 0;
}

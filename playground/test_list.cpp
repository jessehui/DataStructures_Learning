//
//  test_list.cpp
//  datastucture_test
//
//  Created by Jesse. on 11/27/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

// You are given two linked lists representing two non-negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };






ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        
        //建立一个存放结果的链表
        //ListNode head(0);     //leetcode平台runtime error
        ListNode *head = new ListNode(0);
        ListNode* result = head;
//        for(int i = 1; i<10;i++)
//        {
//            result->next = new ListNode(0);
//            result = result->next;
//        }
    
        result = head;
        int c = 0; 	//carry bit
        int i = 3;
        while(result!=NULL)
        {
            int sum = node1->val + node2->val + c;
            if(sum>=10)
            {
                sum = sum - 10;
                c = 1;
            }
            else
                c = 0;
            
            result->val = sum;
       //     cout << "sum = " << sum << endl;
            
            
           
            if(node1->next == NULL && node2->next == NULL && c == 0)
                break;
            else
            {
                result->next = new ListNode(0);
                result = result->next;
            }

            
            if(node1->next == NULL)
                node1->next = new ListNode(0);
            node1 = node1->next;
            
            if(node2->next == NULL)
                node2->next = new ListNode(0);
            node2 = node2->next;
          
    //        i--;
        }
        //
    
        result = head;
        // cout << "final: " << result->val << endl;
        return result;
        
}

void print_list(ListNode *l)
{
    ListNode *p = l;
    while(p != NULL)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
}


int main()
{
    ListNode head1(3);  //定义这个是为了很快返回链表头
    ListNode *l1 = &head1;
    for(int i = 1; i<2; i++)
    {
        l1->next= new ListNode(i+3);
        l1 = l1->next;
    }
    l1 = &head1;
    print_list(l1);
    
    ListNode head2(9);
    ListNode *l2 = &head2;
    for(int i = 1; i < 4; i++)
    {
        l2->next = new ListNode(9-i);
        l2 = l2->next;
    }
    l2 = &head2;
    print_list(l2);
    
    ListNode *result = addTwoNumbers(l1, l2);
    print_list(result);
    
    
    free;
    return 0;
    
}













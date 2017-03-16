/*
Given a sorted linked list, delete all duplicates 
such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//fast enough 9ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head == nullptr || head->next == nullptr)
        // 	return head;

        ListNode *dummy = head;
        ListNode* temp;
        while(head!= nullptr)
        {
        	temp = head;
        //	cout << "temp->val = " << temp->val << endl;
        	//head = head->next;
        	while(head!= nullptr && head->val == temp->val)
        	{
        		head = head->next;
        	}
        	temp->next = head;

        }
        return dummy;
    }
};




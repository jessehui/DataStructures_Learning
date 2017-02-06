/*
Given a linked list and a value x, partition it such that all nodes 
less(!!) than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in 
each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	if(head == nullptr)
    		return nullptr;
    	ListNode less_dummy(0);	//the new list which has all the less-than-x elements
    	ListNode ori_dummy(0);	//original list
    	ori_dummy.next = head;

    	ListNode *current_ori = &ori_dummy;
    	ListNode *current_less = &less_dummy;
    	while(current_ori->next != nullptr)
    	{
    		if(current_ori->next -> val < x)
    		{
    			//add new element to less list
    			current_less->next = current_ori->next;
    			current_less = current_less->next;

    			//connect old list
    			current_ori->next = current_ori->next->next;
    		}

    		else
    			current_ori = current_ori->next;

    	}

    	current_ori = &ori_dummy;
    	current_less->next = current_ori->next;
    	current_less = &less_dummy;
    	return current_less->next;

        
    }
};














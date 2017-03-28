/*

Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//mess
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        	return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *current = head;
        head = dummy;
        while(current->next != nullptr)
	    {
	        if(current->val == current->next->val)
	        {
	        	//int temp = current->val;
	        	while(current->val == current->next->val)
	        	{
	        		current = current->next;
	        	}
	        	current = current->next;
	        	dummy->next = current;
	        	if(current->next != nullptr && current->next->val != current->val)
	        	    dummy = dummy->next;
	        	
	        }
	        else
	        	current = current->next;

	    }

	    return head->next;



    }
};


//
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        	return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;


        ListNode* current = head;
        head = dummy;
        while(current->next!=nullptr)
        {
        	if(current->val == current->next->val )
        	{
        		while(current->next != nullptr && current->val == current->next->val)
        		{
        			current = current->next;
        		}
        		if(current->next == nullptr)
        		{
        		    head->next = nullptr;
        		    break;
        		}

        		//current->next->val != current->val
        		current = current->next;
        		if(current->next!=nullptr)
        		{
        			if(current->val != current->next->val)
        			{
        				head->next = current;
        				head = head->next;
        				current = current->next;
        			}
        		}
        		else
        		{
        			head->next = current;
        			break;
        		}
        	}

        	else
        	{
        	    head->next = current;
        	    head = head->next;
        	    current = current->next;
        	}
        		
            cout << "current->val = " << current->val << endl;

        }

        return dummy->next;
    }
};









//[1,1,2,2,2,3,3,4,5,7,7,9,9,10]



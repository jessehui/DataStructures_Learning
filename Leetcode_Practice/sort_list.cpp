/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
	    
        if(head == nullptr || head->next == nullptr)
        	return head;
        ListNode* fast = head;
        ListNode* slow = head;	//1,3,5..
        //divide the list to two groups
        ListNode* pre = nullptr;
        while(fast!=nullptr && fast->next != nullptr)
        {
           
        	
        	fast = fast->next->next;
        	pre = slow;
        	slow = slow->next;
        }
        pre->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1,l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
    	ListNode* dummy = new ListNode (0);
    	ListNode* head = dummy;
    	while(l1!=nullptr || l2!=nullptr)
    	{
    		if(l1 == nullptr)
    		{
    			head->next = l2;
    			head = head->next;
    			l2 = nullptr;
    		}

    		else if(l2 == nullptr)
    		{
    			head->next = l1;
    			head = head->next;
    			l1 = nullptr;
    		}

    		else
    		{
    			if(l1->val < l2->val)
    			{
    	//		    cout << "if l1 = " << l1->val << endl;
    				head->next = l1;
    				l1 = l1->next;
    			}
    			else
    			{
    				head->next = l2;
    				l2 = l2->next;
    			}

    			head = head->next;
    		}


    	}
    // 	head = dummy->next;
    //     while(head != nullptr)
    // 	{
    // 		cout << head->val << " , " ;
    // 		head = head->next;
    // 	}
    //	cout << endl;
    	return dummy->next;
    }
};
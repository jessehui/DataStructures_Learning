/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.



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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int step = 0;
        while(step<m-2)
        {
        	head = head->next;
        	step++;
        }
        
        ListNode *start = head;//arrive at the one previous place where the reverse start
        if(m == 1)
            start = dummy;
        
        while(step<n-1)
        {
        	head = head->next;
        	step++;
        }

        ListNode *end = head->next;	//next node after the last which needs to reverse
        int num = n-m+1;
     //   cout << "start->next = " << start->next->val << endl;
      //  cout << "end = " << end->val << endl;
        start->next = reverse_list(start->next, end, num);
        return dummy->next;

    }

private:
	ListNode* reverse_list(ListNode* head, ListNode* end, int num)	//number of nodes need to be reversed (num >= 2)
	{
		

		if(num == 1)
		{
			return head;
		}
		

		else
		{
		    ListNode* second = head->next;
			ListNode *new_head = reverse_list(second, end, num-1);
			second->next = head;
			head->next = end;
			return new_head;
		}
	}
};






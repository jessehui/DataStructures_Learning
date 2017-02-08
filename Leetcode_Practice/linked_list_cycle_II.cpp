/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;

        //ListNode *temp = head;
        unordered_set<ListNode *> node_addr;
        while(head!=nullptr)
        {
        	
        	if(node_addr.count(head))
        		return head;
        	node_addr.insert(head);
        	head = head->next;
        	
        }
        return nullptr;

    }
};


//without extra space
//we can do the things that have been explained by others.

// We can move a node from head and node from the meeting 
//point, then when they meet, it is the
// start point of the cycle.
class Solution{
public:
	ListNode *detectCycle(ListNode *head){
		if(head == nullptr)
			return nullptr;

		ListNode *dummy = head;
		ListNode *runner = head;
		ListNode *walker = head;

		while(runner->next != nullptr && runner->next->next != nullptr)
		{
			walker = walker->next;
			runner = runner->next->next;
			if(walker == runner)	//find the loop
			{
				walker = dummy;
				while(walker != runner)		//head and meet point have the same distance away from the start point
				{
					walker = walker->next;
					runner = runner->next;
				}
				return walker;
			}

		}

		return nullptr;
	}
};

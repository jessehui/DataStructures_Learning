/*

Given a linked list, determine if it has a cycle in it.

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

//there might be small loop

//accepted but slow
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;

        //ListNode *temp = head;
        unordered_set<ListNode *> node_addr;
        while(head!=nullptr)
        {
        	
        	if(node_addr.count(head))
        		return true;
        	node_addr.insert(head);
        	head = head->next;
        	
        }
        return false;

    }
};

//another method
//another method
class Solution {
public:
    bool hasCycle(ListNode *head) {
  		if(head == nullptr)
            return false;
  		ListNode *runner = head;	//
  		ListNode *walker = head;

  		//if write runner->next->next != nullptr it is wrong, because runner->next might be a nullptr already
  		while(walker->next != nullptr && runner->next != nullptr && runner->next->next != nullptr)
  		{
  			
  			walker = walker->next;
  			runner = runner->next->next;	
  			if(walker == runner)	//if there is a loop walker and runner will eventually meet
  				return true;
  			
  		}

  		return false;

    }
};


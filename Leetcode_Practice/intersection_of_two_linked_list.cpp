/*

Write a program to find the node at which the 
intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

//Accepted 40%
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode *> nodes;
        while(headA != nullptr)
        {
        	nodes.insert(headA);
        	headA = headA->next;
        }

        while(headB != nullptr)
        {
        	if(nodes.count(headB))
        	{
        		return headB;
        	}
        	headB = headB->next;
        }


        //no intersection
        return nullptr;


    }
};


//another try
//I believe it works. But it change the structure because of reverse
class Solution {
private:
	ListNode *reverseList(ListNode *head)
	{
		if(head == nullptr || head->next == nullptr)
			return head;
		ListNode *second = head->next;
		ListNode *new_head = reverseList(second);
		second->next = head;
		head->next = nullptr;
		return new_head;
	}

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *newA = reverseList(headA);
    	ListNode *newB = reverseList(headB);
    	if(newA != newB)
    		return nullptr;
    	
    	while(newA != nullptr && newB != nullptr)
    	{
    		if(newA->next == newB->next)
    		{
    			newA = newA -> next;
    			newB = newB -> next;
    		}
    		else	
    			return newA;

    	}

    	return nullptr;

    }
};

//another method
//Accepted 47%
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == nullptr || headB == nullptr)
    		return nullptr;

    	ListNode *tempA = headA;
    	ListNode *tempB = headB;
    	int i = 0;
    	while(i<2)
    	{
    		if(tempA == tempB)
    			return tempA;
    		else
    		{
    			tempA = tempA->next;
    			tempB = tempB->next;
    		}

    		if(tempA == nullptr)
    		{
    			tempA = headB;
    			i++;
    		}
    		if(tempB == nullptr)
    		{
    			tempB = headA;
    		}
    	}

    	return nullptr;	

    }
};



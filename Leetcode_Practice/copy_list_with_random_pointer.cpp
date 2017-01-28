/*A linked list is given such that each node contains an
additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

//深度拷贝一个链表, 因为链表中有random指针和next指针都要拷贝

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

//The first half of the input is the label values of each node,
// while the second half of the input is the label values of each random node.


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
        	return nullptr;

      	unordered_map<RandomListNode*, RandomListNode*> ptr_map;	//<key, value> = <old, new>存新旧节点的对应关系
      	//存random关系没用, 因为如果存random,存的是地址的对应关系. 对于新建的链表,地址都对不上.

      	RandomListNode *dummy = new RandomListNode(0);
      	RandomListNode *copy = dummy;
      	RandomListNode *current = head;
      	
      	//copy the node to the new list
      	while(current != nullptr)
      	{
      		RandomListNode *new_node = new RandomListNode(current->label);
      		copy->next = new_node;
  			copy = copy->next;

      		// if(current->random!=nullptr)		//所有点都要存, 不能只存有random的点
      		// {
      			copy->random = current->random;
      			ptr_map[current] = copy;	//	<key: old, value: new>
      			
      		// }

      		current = current->next;

      	}

      	//clear the connection of the random pointer
      	current = dummy->next;
      	while(current!=nullptr)
      	{
      		if(current->random != nullptr)
      		{
      			current->random = ptr_map[current->random];
      		}
      		current = current->next;
      	}
      	
      	return dummy->next;

    }
};
// You are given two linked lists representing two non-negative numbers. 
//The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        
        //建立一个存放结果的链表
        //ListNode head(0);     //leetcode平台runtime error xcode能跑通
        
        ListNode *head = new ListNode(0);//为了直接返回链表头
        ListNode* result = head;
        result = head;
        int c = 0; 	//carry bit
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
            
            if(node1->next == NULL && node2->next == NULL && c == 0)
                break;
            else    //再建立一个元素
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
          

        }
    
        result = head;
        // cout << "final: " << result->val << endl;
        return result;
        
}
};





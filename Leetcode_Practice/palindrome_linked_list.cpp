/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        ListNode *copy = head;
        vector<int> node;
        while(copy!=nullptr)
        {
        	node.push_back(copy->val);
        	copy = copy->next;
        }

        int left = 0, right = node.size()-1;
        while(left < right)
        {
        	if(node[left] != node[right])
        		return false;
        	left++;
        	right--;
        }
        return true;
    }
};
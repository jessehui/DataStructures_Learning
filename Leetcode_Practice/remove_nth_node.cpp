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
    ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head->next == nullptr)
        return nullptr;
    
    int length = 1;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;     //如果除去的是head
    
    while(head->next != nullptr)
    {
        head = head->next;
        length ++ ;
    }
//    cout << "length = " << length << endl;

    head = dummy->next;
    if(length == n)//去掉head
    {
        head = head->next;
        return head;
    }
        
    for(int i = 0; i < length - n - 1; i++)
    {
        head = head->next;
    }
    
    head->next = head->next->next;
    
    return dummy->next;
}
};
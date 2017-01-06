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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // if(l1 == nullptr)
    //     return l2;
    // if(l2 == nullptr)
    //     return l1;
    
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while(l1 != nullptr || l2 != nullptr)//while直到两个都为空
    {
        if(l1 == nullptr)
        {
            head->next = l2;
            break;
        }
        else
            if(l2 == nullptr)
            {
                head -> next = l1;
                break;
            }
        
        if(l1->val < l2->val)
        {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
    //    print_list(temp->next);
    }
  //  cout << endl;
 //   print_list(temp->next);
    return temp->next;;
    
        
    
}
};
/*Sort a linked list using insertion sort.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//wrong, messy
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* current = head;
        ListNode* second = current->next;
        ListNode* min_ = head;
        while(current->next!=nullptr)
        {
            cout << "current = " << current->val << endl;
            if(current->val <= second->val)
            {
                current = second;
                second = second->next;
            }
            else
            {
                ListNode* anchor = current;
                ListNode* pre = current;
                while(second != nullptr && current->val > second->val)
                {
                    pre = second;
                    second = second->next;
                }
                
                if(second == nullptr)
                {
                    current = pre;
                    goto test;
                }
                pre->next = current;
                anchor = current->next;
                current->next = second;
                current = anchor;
                second = current->next;
                
                cout << "After current = " << current->val << endl;
                
            }
            cout << "comparison:  ";
            cout << "current = " << current->val << "  min_ = " << min_->val << endl ;
  test:          if(current->val < min_->val)
            {
                cout << "test" << endl;
                min_ = current;
                min_->next = head;
                head = min_;
                current = head;
                second = current->next;
                cout << "End current = " << current->val << endl;
            }


            
        }
        return head;


    }
};


//another try
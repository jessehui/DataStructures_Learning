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
    ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* new_dummy = dummy;
    
    ListNode* head2 = head->next;
    ListNode* new_head = head2->next;
    
    head2->next = head;
    head->next = new_head;
    dummy->next = head2;
    
//    print_list(dummy->next);

    if(head->next == nullptr)   //这个时候已经调换位置了, 最后一个数是head
        return dummy->next;


 
    for(int i = 0; i < 3; i++)//set the position of head2
        head2 = head2->next;
    
    new_dummy = head;
    head = new_head;    // set the position of head1
    
    while(head2 != nullptr)
    {
        
        new_head = head2->next;
        
        
        //swap
        head2->next = head;
        head->next = new_head;
        new_dummy->next = head2;
        
//        print_list(dummy->next);
        
        if(head->next == nullptr)   //这个时候已经调换位置了, 最后一个数是head
            break;
        
        for(int i = 0; i < 3; i++)//set the position of head2
        {
      //      cout << "(i = " << i << ")  " ;
        
            head2 = head2->next;
        }
        
   //     cout << endl;
        new_dummy = head;   //set the position of new dummy
        
        head = new_head;    // set the position of head1
        
       
//        print_list(dummy->next);
     //   cout << endl;
    }
    
    return dummy->next;
}

};
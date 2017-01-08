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
   ListNode* rotateRight(ListNode* head, int k) {
    
    if(k==0 || head == nullptr || head->next == nullptr )
        return head;
    
    
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int length = 0;
    
    while( head!= nullptr )
    {
        length++;
        head = head->next;
    }
    
    head = dummy->next;
    
//    cout << " length = " << length;
    if(k >= length)
    {
        k = k%length;
        if( k == 0 )
            return head;
    }
    
//    cout << "  ; k = " << k << endl;
    
    
    for(int i = 0; i < length - k - 1 ;i++)  //到达 把对应的next设为nullptr
    {
        head = head->next;
    }
    
//    cout << "val = " << head->val << endl;

    //获得需要rotate的头地址
    ListNode *rotate = head->next;
    
    //把后边的尾巴斩断
    head->next = nullptr;
    
    //开始连接
    head = rotate;
    while(rotate->next != nullptr)
    {
        rotate = rotate->next;
    }
    
    //到达需要拼接的位置
    rotate->next = dummy->next;
    
    return head;
    
    
    
}




};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        int carry=0;
        
        while(l1 || l2){
            int add=0;
            if(l1){
                add += l1->val;
                l1 = l1->next;
            }
                
            if(l2){
                add += l2->val;
                l2 = l2->next;
            }
                
            add += carry;
            
            int data = add%10;
            carry = add/10;
            
            pre->next = new ListNode(data);
            pre = pre->next;
        }
        if(carry)
            pre->next = new ListNode(carry);
        
        return dummy->next;
        
    }
};
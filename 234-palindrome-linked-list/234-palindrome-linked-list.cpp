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
    ListNode* reverse(ListNode* cur){
        
        ListNode *prev=NULL;
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head1) {
        
        if(head1==NULL or head1->next==NULL)
            return true;
        
        ListNode *tmp=NULL, *slow = head1, *fast = head1;
        
        while(fast!=NULL && fast->next!=NULL){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp->next  = NULL;
        //slow is at mid
        
        ListNode* head2 = reverse(slow);
        
        while(head1 && head2 &&  head1->val == head2->val){
            head1 = head1->next;
            head2 = head2->next;
        }
        
        if(head1==NULL or head2==NULL)
            return true;
        return false;
    }
};
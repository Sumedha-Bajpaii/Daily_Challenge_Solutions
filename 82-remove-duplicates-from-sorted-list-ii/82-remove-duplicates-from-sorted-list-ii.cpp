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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* s = dummy;
        
        while(s && s->next){
            auto f = s->next;
            while(f->next && f->val == f->next->val)
                f = f->next;
            if(s->next == f)
                s = f;
            else
                s->next = f->next;
        }
        return dummy->next;
    }
};
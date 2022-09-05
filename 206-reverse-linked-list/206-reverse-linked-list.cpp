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
    ListNode* f(ListNode* pre, ListNode* cur){
        if(cur==NULL)
            return pre;
        
        ListNode* next = cur->next;
        cur->next = pre;
        return f(cur,next);
    }
    
    ListNode* reverseList(ListNode* head) {
        
        return f(NULL, head);
    }
};
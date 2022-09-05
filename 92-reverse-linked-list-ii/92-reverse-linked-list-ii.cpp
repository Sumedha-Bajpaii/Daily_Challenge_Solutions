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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *start, *end, *temp=dummy;
        
        for(int cnt=0; cnt<=right; cnt++){
            if(cnt == left-1)
                start = temp;
            if(cnt == right)
                end = temp;
            temp = temp->next;
        }
        
        temp = start->next;
        
        //reverse here
        ListNode *pre=start->next, *cur = pre->next;
        while(pre != end){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        // start->next = end;
        start->next = pre;
        temp->next = cur;
        
        return dummy->next;
    }
};
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
        
        int cnt = 1;
        ListNode *temp=new ListNode(-1), *cur=head;
        
        while(cnt < left){ 
            temp = cur;
            cur = cur->next;
            cnt++;
        }
        ListNode *pre = cur, *start = cur;
        cur = cur->next;
        cnt++;
        
        while(cnt<=right){
            //reverse here
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            cnt++;
        }
        temp->next = pre;
        start->next = cur;
        
        if(left==1)
            return temp->next;
        
        return head;
    }
};
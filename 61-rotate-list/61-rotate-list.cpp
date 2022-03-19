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
    int length(ListNode* temp){
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        int len = length(head);
        k = k%len;
        
        ListNode *pre = head, *tail = head;
        
        while(k){
            tail = tail->next;
            k--;
        }
        
        while(tail->next){
            pre = pre->next;
            tail = tail->next;
        }
        
        tail->next = head;
        ListNode *newHead = pre->next;
        pre->next = NULL;
        return newHead;
    }
};
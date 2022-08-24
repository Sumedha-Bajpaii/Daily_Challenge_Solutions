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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
            return head;
        ListNode *oddStart=head, *odd=head;
        ListNode *evenStart=head->next, *even=head->next;
        
        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = evenStart;
        return head;
    }
};
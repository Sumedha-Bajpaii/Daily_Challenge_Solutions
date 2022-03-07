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
class compare{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(auto &head: lists)
            if(head)
                pq.push(head);
        
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();
            
            if(cur->next!=nullptr)
                pq.push(cur->next);
            
            tail->next = cur;
            tail = tail->next; 
        }
        
        return dummy->next;
    }
};
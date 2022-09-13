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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//lists: vector of head pointers of linkedLists.... not a vector of whole list
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> minHeap;
        
        for(ListNode *head: lists){
            if(head != NULL)
                minHeap.push({head->val,head});
        }
        
        ListNode *start = new ListNode(), *cur = start;
        
        while(!minHeap.empty()){
            ListNode* ptr = minHeap.top().second;
            minHeap.pop();
            
            cur->next = ptr;
            cur = cur->next;
            ptr = ptr->next;
            
            if(ptr != NULL)
                minHeap.push({ptr->val,ptr});
        }
        
        return start->next;
    }
};
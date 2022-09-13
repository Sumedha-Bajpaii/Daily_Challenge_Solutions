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
    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        
        if(l1->val <= l2->val){
            l1->next = merge2lists(l1->next,l2);
            return l1;
        }
        l2->next = merge2lists(l1,l2->next);
        return l2;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return NULL;
        int len = lists.size();
        while(len > 1){   
            for(int i=0; i<len/2; i++){
                lists[i] = merge2lists(lists[i], lists[len-1-i]);
            }
            len = (len+1)/2;
        }
        return lists[0];
    }
};
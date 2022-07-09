class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue< pair<int,vector<int>> > maxHeap;
        
        for(auto i:nums1){
            for(auto j:nums2){
                
                if(maxHeap.size()>=k){
                    if(maxHeap.top().first > i+j){
                        maxHeap.pop();
                        maxHeap.push({i+j,{i,j}});                    
                    }
                    else{
                        break;
                    }
                }
                else{
                    maxHeap.push({i+j,{i,j}});
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            auto item = maxHeap.top();
            ans.push_back(item.second);
            maxHeap.pop();
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> next(n+1,0), cur(n+1,0);
        
        for(int i=n-1; i>=0; i--){
            for(int last = i-1; last>=-1; last--){
                int take = 0;
                if(last==-1 || nums[last]<nums[i])
                    take = 1 + next[i+1];
                int notTake = next[last+1];
                
                cur[last+1] = max(take,notTake);
            }
            next = cur;
        }
        
        return next[0];
    }
};
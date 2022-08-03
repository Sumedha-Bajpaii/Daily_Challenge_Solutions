class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> pre,suf;
        pre.push_back(1);
        suf.push_back(1);
        
        for(int i=0;i<n; i++){
            pre.push_back(pre.back()*nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            suf.push_back(suf.back()*nums[i]);
        }
        reverse(suf.begin(),suf.end());
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(pre[i]*suf[i+1]);
        }
        
        return ans;
    }
};
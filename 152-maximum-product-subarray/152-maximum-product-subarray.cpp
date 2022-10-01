class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN, cur=1, n=nums.size();
        
        for(int i=0; i<n; i++){
            cur = cur * nums[i];
            // cout<<cur<<" ";
            ans = max(cur,ans);
            if(cur==0)
                cur = 1;
        }
        cur = 1;
        // cout<<endl;
        for(int i=n-1; i>=0; i--){
            cur = cur * nums[i];
            // cout<<cur<<" ";
            ans = max(cur,ans);
            if(cur==0)
                cur = 1;
        }
        
        return ans;
    }
};
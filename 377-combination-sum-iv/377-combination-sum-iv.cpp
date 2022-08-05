class Solution {
public:
    int f(int target,vector<int> &nums,vector<int> &dp){
        
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        
        int ans=0;
        for(auto x:nums){
            if(x<=target){
                ans += f(target-x,nums,dp);
            }
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1,-1);
        return f(target,nums,dp);
    }
};

// class Solution {
// public:
//     int f(int i,int target,vector<int> &nums){
//         if(i==nums.size()){
//             if(target==0)
//                 return 1;
//             else
//                 return 0;
//         }
        
//         int t=0, nt=0;
//         if(nums[i] <= target){
//             t = f(i,target-nums[i],nums);
//         }
//         nt = f(i+1,target,nums);
        
//         return t+nt;
//     }
    
//     int combinationSum4(vector<int>& nums, int target) {
//         return f(0,target,nums);
//     }
// };

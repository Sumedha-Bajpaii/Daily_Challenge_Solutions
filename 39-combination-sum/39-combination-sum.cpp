class Solution {
public:
    void f(int i,int target,vector<int> &nums,vector<int> cur, vector<vector<int>> &res){
        if(i==nums.size()){
            if(target==0){
                res.push_back(cur);
            }
            return;
        }
        
        f(i+1,target,nums,cur,res);
        
        if(nums[i]<=target){
            cur.push_back(nums[i]);
            f(i,target-nums[i],nums,cur,res);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        f(0,target,nums,{},res);
        return res;
    }
};
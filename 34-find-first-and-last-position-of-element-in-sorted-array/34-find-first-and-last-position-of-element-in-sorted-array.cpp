class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto ff = lower_bound(nums.begin(), nums.end(),target);
        int iff = ff-nums.begin();
        
        auto fs = upper_bound(nums.begin(), nums.end(),target);
        int ifs = fs-nums.begin();
        
        if(iff==nums.size() || nums[iff]!=target)
            return {-1,-1};
        
        vector<int> ans;
        ans.push_back(iff);
        ans.push_back(ifs-1);
        return ans;
    }
};

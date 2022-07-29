class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxR = 0, i=0;
        
        for(i=0; i<nums.size(); i++){
            if(i<=maxR)
                maxR = max(maxR,i+nums[i]);
            else
                break;
        }
        
        if(i==nums.size())
            return true;
        return false;
    }
};
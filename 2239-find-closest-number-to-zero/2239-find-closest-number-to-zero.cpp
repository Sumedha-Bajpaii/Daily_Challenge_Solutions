class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int res=0, d=INT_MAX;
        
        for(auto x: nums){
            if(abs(x-0)<=d){
                d = abs(x-0);
                res = x;
            }
        }
        return res;
    }
};
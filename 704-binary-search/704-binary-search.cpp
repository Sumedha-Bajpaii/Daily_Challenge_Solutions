class Solution {
public:
    int search(vector<int>& nums, int targ) {
        
        int lo=0, hi=nums.size()-1;
        
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(nums[mid]==targ)
                return mid;
            else if(targ < nums[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }
};
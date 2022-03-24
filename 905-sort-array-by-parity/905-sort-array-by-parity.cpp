class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i=0, j=nums.size()-1;
        
        while(i<j)
        {
            if(nums[i]%2==0)
                i++;
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return nums;
    }
};
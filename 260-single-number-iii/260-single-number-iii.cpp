class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long int n = 0;
        for(auto num: nums){
            n = n^num;
        }
        
        //n is xor of 2 resultant numbers;
        //find first set bit from right in n;
      
        long long mask = n&-n;
        
        int ans1=0, ans2=0;
        
        for(auto num: nums){
            if(num&mask)
                ans1 ^= num;
            else
                ans2 ^= num;
        }
        
        return {ans1,ans2};
    }
};
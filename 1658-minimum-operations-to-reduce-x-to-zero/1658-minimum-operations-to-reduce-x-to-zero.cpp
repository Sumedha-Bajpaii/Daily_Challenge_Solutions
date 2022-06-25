class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total=0;
        for(auto e: nums)
            total += e;
        
        int targ = total-x;   //11-5=6 find maximum size subarray of sum = targ
        
        int i=0, j=0, sum=0, n=nums.size(), len=0;
    
        if(targ < 0)    return -1;
        if(targ==0)     return n;
        
        while(j<n){
            sum += nums[j];
            
            while(sum > targ){
                sum -= nums[i];
                i++;
            }
            
            if(sum == targ){
                len = max(len,j-i+1);
                sum -= nums[i];
                i++;
            }
            
            j++;
        }
        
        if(len==0)
            return -1;
        return n-len;
    }
};
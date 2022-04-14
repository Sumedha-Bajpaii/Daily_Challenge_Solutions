class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k==0)
            return 0;
        
        int n = nums.size();
        int i=0, j=0, cnt=0, prod=1;
        
        while(j<n){
            
            prod *= nums[j];
            
            if(prod<k){
                cnt += j-i+1;
            }
            else{
                while(prod >= k && i<=j){
                    prod /= nums[i];
                    i++; 
                }
                //remaining valid window
                // int sz = j-i+1;
                // cnt += (sz*(sz+1))/2;
                cnt += j-i+1;
            }
            j++;
        }
        
        return cnt;
    }
};
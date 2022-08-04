class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = 0;
        for(auto num: nums){
            n = n^num;
        }
        
        //n is xor of 2 resultant numbers;
        //find first set bit from right in n;
        
        int cnt=0;
        while((n&1)==0){
            
            cnt++;
            n = n>>1;
        }
        
        int mask=1;
        mask = mask<<cnt;
        
        //cout<<cnt<<" "<<mask<<endl;
        
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
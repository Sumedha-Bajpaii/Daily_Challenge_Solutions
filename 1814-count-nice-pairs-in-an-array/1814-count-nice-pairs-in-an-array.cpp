class Solution {
public:
    int rev(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int mod = 1e9 + 7;
        unordered_map<int,int> mp;
        long long cnt=0;
        
        for(int j=0; j<nums.size(); j++){
            int d = nums[j] - rev(nums[j]);
            if(mp.find(d) != mp.end()){
                cnt += mp[d];
            }
            mp[d]++;
        }
        
        int ans = cnt % mod;
        return ans;
    }
};
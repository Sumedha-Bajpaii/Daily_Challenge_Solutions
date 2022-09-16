class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        if(n%2 != 0)    return res;
        
        unordered_map<int,int> mp;
        for(int x: nums)
            mp[x]++;
        
        sort(nums.begin(),nums.end());
        
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
    
            if(ele%2!=0 || mp[ele]<=0)  
                continue;
            mp[ele]--;
            
            if(mp[ele/2] <= 0){
                mp[ele]++;
                continue;
            }
            mp[ele/2]--;
            res.push_back(ele/2);
        }
        
        if(res.size() == n/2)
            return res;
        return {};
    }
};
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> L(n,0);
        vector<int> R(n,0);
        
        int mx = nums[0];
        for(int i=0; i<n; i++){
            mx = max(mx,nums[i]);
            L[i] = mx;
        }
        
        int mn = nums[n-1];
        for(int i=n-1; i>=0; i--){
            mn = min(mn,nums[i]);
            R[i] = mn;
        }
        
        // for(auto x:nums)
        //     cout<<x<<" ";
        // cout<<endl;
        //  for(auto x:L)
        //     cout<<x<<" ";
        // cout<<endl;
        //  for(auto x:R)
        //     cout<<x<<" ";
        // cout<<endl;
        
        int sz=0;
        for(int i=0; i<n; i++){
            if(L[i]<=R[i+1]){
                sz = i+1;
                break;
            }
        }
        
        return sz;
    }
};
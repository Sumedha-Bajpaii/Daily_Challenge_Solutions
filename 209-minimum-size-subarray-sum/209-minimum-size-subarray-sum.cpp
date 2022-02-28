class Solution {
public:
    int minSubArrayLen(int targ, vector<int>& a) {
        
        int sm=0, ans=INT_MAX, i=0, j=0;
        while(j<a.size()){
            sm += a[j];
            
            while(sm>=targ){
                ans = min(ans,j-i+1);
                sm -= a[i];
                i++;
            }
            j++;
        }
        
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
    }
};
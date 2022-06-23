class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(),special.end());
        int n = special.size();
        int ans = max(0, special[0]-bottom);
        
        for(int i=1; i<n; i++){
            int gap = special[i]-special[i-1]-1;
            ans = max(ans, gap);
        }
        ans = max(ans,top-special[n-1]);
        
        return ans;
    }
};
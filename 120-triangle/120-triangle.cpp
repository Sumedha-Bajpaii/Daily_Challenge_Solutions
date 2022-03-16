class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        
        int n = T.size();
        vector<int> prev(n);
        
        for(int j=0; j<n; j++)
            prev[j] = T[n-1][j];
        
        for(int i=n-2; i>=0; i--){
            vector<int> cur(i+1);
            for(int j=i; j>=0; j--){
                cur[j] = T[i][j] + min(prev[j], prev[j+1]);  
            }
            prev = cur;
        }
        
        return prev[0];
    }
};
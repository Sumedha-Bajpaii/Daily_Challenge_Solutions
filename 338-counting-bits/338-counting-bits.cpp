class Solution {
public:
    int ones(int n){
        int cnt=0;
        
        while(n){
            if(n&1)
                cnt++;
            n = n>>1;
        }
        
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1,0);
        
        for(int i=0; i<n+1; i++){
            ans[i] = ones(i);
        }
        
        return ans;
    }
};
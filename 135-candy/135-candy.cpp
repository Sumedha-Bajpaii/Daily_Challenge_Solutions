class Solution {
public:
    int candy(vector<int>& a) {
        
        int n = a.size();
        vector<int> candy(n,1);
        
        for(int i=1; i<n; i++){
            if(a[i]>a[i-1])
                candy[i] = candy[i-1]+1;
        }
        
        for(int i=n-2; i>=0; i--){
            if(a[i]>a[i+1] && candy[i]<=candy[i+1])
                candy[i] = candy[i+1]+1;
        }
        
        int res=0;
        for(int c:candy)
            res += c;
        
        return res;
    }
};
class Solution {
public:
    int f(vector<int> &one,vector<int> &two,int targ){
        
        int n = one.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(one[i]!=targ)
            {
                if(two[i]==targ)
                    cnt++;
                else
                    return INT_MAX;
            }
        }
        return cnt;
    }
    
    int minDominoRotations(vector<int>& top, vector<int>& bot) {
        
        int ans=INT_MAX;
        
        ans = min(ans, f(top,bot,top[0]) );
        ans = min(ans, f(top,bot,bot[0]) );
        ans = min(ans, f(bot,top,top[0]) );
        ans = min(ans, f(bot,top,bot[0]) );
        
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};
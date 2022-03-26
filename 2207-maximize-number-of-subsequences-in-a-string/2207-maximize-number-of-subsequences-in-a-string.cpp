class Solution {
public:
    long long maximumSubsequenceCount(string s, string p) 
    {
        long long cnt1=0, cnt2=0;
        long long res=0;
        
        for(auto c : s){
            if(c == p[0]){
                cnt1++;
            }
            else if(c==p[1]){
                cnt2++;
                res += cnt1;
            }
        }
        if(p[0]==p[1])
        {
            res += ((cnt1-1)*cnt1)/2;
        }
        return max(res+cnt2, res+cnt1);
    }
};
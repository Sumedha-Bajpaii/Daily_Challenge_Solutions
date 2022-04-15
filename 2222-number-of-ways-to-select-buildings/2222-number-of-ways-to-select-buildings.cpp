class Solution {
public:
    long long numberOfWays(string s) {
        
        int total0=0, total1=0;
        
        for(auto c: s){
            if(c=='0')
                total0++;
            else
                total1++;
        }
        
        long long ans=0;
        int cur0=0, cur1=0;
        
        for(auto c: s){
            if(c=='0'){
                //ones on left * ones on right --> 101
                ans += cur1 * (total1 - cur1);
                cur0++;
            }
            else{
                //zeroes on lrft * zeroes on right --> 010
                ans += cur0 * (total0 - cur0);
                cur1++;
            }
        }
        
        return ans;
    }
};
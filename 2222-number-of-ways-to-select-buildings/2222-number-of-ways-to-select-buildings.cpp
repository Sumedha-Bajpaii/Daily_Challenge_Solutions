class Solution {
public:
    long long numberOfWays(string s) {
        
        int n = s.size();
        vector<long long> n01(n,0), n10(n,0);
        int z=0, one=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='0')
                z++;
            if(i>0){
                if(s[i]=='1')
                    n01[i] = n01[i-1] + z;
                else
                    n01[i] = n01[i-1];
            }
            
            if(s[i]=='1')
                one++;
            if(i>0){
                if(s[i]=='0')
                    n10[i] = n10[i-1] + one;
                else
                    n10[i] = n10[i-1];
            }
        }
        
        //x = 010 count     y = 101 count
        long long x=0, y=0;
        for(int i=2; i<n; i++){
            if(s[i]=='0')
                x += n01[i-1];
            else
                y += n10[i-1];
        }
        return x+y;
    }
};
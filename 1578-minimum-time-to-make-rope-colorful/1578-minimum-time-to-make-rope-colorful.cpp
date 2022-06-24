class Solution {
public:
    int minCost(string s, vector<int>& time) {
        
        int res=0, n=s.size();
        
        for(int i=0; i<n; i++){
            int j=i+1, cnt=1, maxt=i, sum=time[i];
            
            while(j<n && s[j]==s[i]){
                cnt++;
                sum += time[j];
                if(time[j] > time[maxt]){
                    maxt = j;
                }
                j++;
            }
            
            if(cnt>1)
                res += sum - time[maxt];
            
            i=j-1;
        }
        
        return res;
    }
};
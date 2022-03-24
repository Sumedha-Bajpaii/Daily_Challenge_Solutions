class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit)
    {
        sort(p.begin(), p.end());
        int n = p.size();
        int i=0, j=n-1;
        
        int boat=1, wt=0, cnt=0;
        while(i<=j){
            
            if(wt+p[j]<=limit && cnt<2){
                wt += p[j];
                cnt++;
                j--;
            }
            else if(wt+p[i]<=limit && cnt<2){
                wt += p[i];
                cnt++;
                i++;
            }
            else{
                boat++;
                wt = 0;
                cnt = 0;
            }
        }
        
        return boat;
    }
};
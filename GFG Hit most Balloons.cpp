class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        
        int ans=INT_MIN;
        for(int i=0; i<N; i++)
        {
            pair<int,int> p = arr[i];
            int x1=p.first, y1=p.second;
            int cnt=0;
            unordered_map<double,int> mp;
            
            for(int j=0; j<N; j++){
                p = arr[j];
                int x2=p.first, y2=p.second;
                if(x1==x2 && y1==y2){
                    cnt++;
                }
                else{
                    double slope = (double)(y2-y1)/(double)(x2-x1);
                    mp[slope]++;
                }
            }
            
            for(auto p:mp){
                ans = max(ans, p.second+cnt);
            }
        }
        return ans;
    }
};

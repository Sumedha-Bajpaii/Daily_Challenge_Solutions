// class cmp{
//     bool operator()(vector<int>& a, vector<int>& b){
//         if(a[1] < b[1]) return true;
//         if(a[1] > b[1]) return false;
//         return a[0] < b[0];
//     }
// };

bool cmp1(vector<int>& a, vector<int>& b){
    if(a[1] < b[1]) return true;
    if(a[1] > b[1]) return false;
    return a[0] < b[0];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        
        if(v.size() == 0)   return 0;
        sort(v.begin(), v.end(), cmp1);
        
        int cur=0, ans=1;
        for(int i=1; i<v.size(); i++){
            if(v[cur][1] < v[i][0]){
                cur = i;
                ans++;
            }
        }
        
        return ans;
    }
};
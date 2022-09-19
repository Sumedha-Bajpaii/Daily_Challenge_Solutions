class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        int n=s.size(), j=0;
        int ans=0,cur=0;
        
        while(j<n){
            if(j==0 || alphabet[s[j]-'a']==alphabet[s[j-1]-'a'+1]){
                cur++;
            }
            else{
                ans = max(ans,cur);
                cur=1;
            }
            j++;
            // cout<<cur<<" ";
        }
        ans = max(ans,cur);
        return ans;
    }
};
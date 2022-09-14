class Solution {
public:
    int check(int left,int right,string s){
        int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++; left--; right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        
        int ans=0;
        for(int i=0; i<s.size(); i++){
            ans += check(i,i,s);       //odd palindrome
            ans += check(i,i+1,s);     //even pal
        }
        return ans;
    }
};
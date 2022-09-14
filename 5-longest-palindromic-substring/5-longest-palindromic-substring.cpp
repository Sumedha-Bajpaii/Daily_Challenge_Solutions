class Solution {
public:
    string check(int left,int right,string s){
        // int count=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            // count++; 
            left--; right++;
        }
        return s.substr(left+1,right-left-1);
    }
    
    string longestPalindrome(string s) {
        
        string ans = "", res;
        
        for(int i=0; i<s.size(); i++){
            res = check(i,i,s);
            if(res.size() > ans.size())
                ans = res;    
            
            res = check(i,i+1,s);
            if(res.size() > ans.size())
                ans = res;   
        }
        return ans;
    }
};
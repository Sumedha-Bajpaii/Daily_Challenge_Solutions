class Solution {
public:
    int myAtoi(string s) {
        
        int pos=0, n=s.size();
        
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                pos = i;
                break;
            }
        }
        
        int sign = 1;
        if(s[pos]=='-'){
            sign = -1;
            pos++;
        }
        else if(s[pos]=='+'){
            pos++;
        }
        else if(s[pos]<'0' || s[pos]>'9')
            return 0;
        
        string str = "";
        while(pos<n && s[pos]>='0' && s[pos]<='9'){
            str += s[pos];
            pos++;
        }
        
        //cout<<sign<<" "<<str<<endl;
        // now simply convert str to int
        
        long long ans = 0;
        for(auto i: str){
            ans = ans*10 + (i-'0');
            
            if(ans-1>INT_MAX)
                break;
        }
        
        long long res = ans*sign;
        if(res<INT_MIN)
            res = INT_MIN;
        if(res>INT_MAX)
            res = INT_MAX;
        
        return res;
    }
};
class Solution {
public:
    string rev(string str)
    {
        std::reverse(str.begin(),str.end());
        return str;
    }
    
    int reverse(int x) {
        
        long long result;
    
        if(x<0)
        {
            string s = to_string(abs(x));
            string res = rev(s);
            res.insert(0, "-");
            result = stoll(res);
        }
        else
        {
            string s = to_string(abs(x));
            string res = rev(s);
            result = stoll(res);
        }
        
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        
        return result;
    }
};
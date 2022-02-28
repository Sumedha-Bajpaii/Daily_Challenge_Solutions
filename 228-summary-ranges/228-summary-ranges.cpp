class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) 
    {
        vector<string> res;
        
        if(a.size()==0)
            return res;
        int l=a[0], r=a[0];
        
        for(int i=1; i<a.size(); i++)
        {
            if(a[i]==a[i-1]+1)
                r = a[i];
            else{
                string s = "";
                s += to_string(l);
                if(r!=l){
                    s += "->";
                    s += to_string(r);
                }
                res.push_back(s);
                l = r = a[i];
            }
        }
        string s = "";
        s += to_string(l);
        if(r!=l){
            s += "->";
            s += to_string(r);
        }
        res.push_back(s);
        
        return res;
    }
};
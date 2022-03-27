class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        
        vector<int> v;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                cnt+=mat[i][j];
            }
            v.push_back(cnt);
        }
        multimap<int,int> m;
        for(int i=0;i<v.size();i++)
        {
            //m.insert(v[i],i);  //change 1
            m.insert({v[i],i});
        }
        vector<int> res;
        
        for(auto i :m)
        {
            res.push_back(i.second);
        }
        
        //while(res.size()>=k)  //change 2
        while(res.size()>k)
            res.pop_back();
        
        return res;
    }
};
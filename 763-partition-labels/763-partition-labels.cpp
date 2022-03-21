class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        int n = s.size();
        unordered_map<char,vector<int> > mp;
        
        for(int i=0; i<n; i++)
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = {i,i};
            else
                mp[s[i]][1] = i;
        }
        
        vector<vector<int>> intervals;
        for(auto p: mp)
            intervals.push_back(p.second);
        
        sort(intervals.begin(),intervals.end());
        
        
        // for(auto v: intervals)
        //     cout<<v[0]<<" "<<v[1]<<endl;
        
        
        vector<int> cur = intervals[0];
        vector<vector<int>> merged;
        
        for(int i=1; i<intervals.size(); i++)
        {
            auto v = intervals[i];
            if(cur[1] > v[0])
                cur[1] = max(cur[1],v[1]);
            else{
                merged.push_back(cur);
                cur = v;
            }
        }
        merged.push_back(cur);
        for(auto v: merged){
            // cout<<v[0]<<" "<<v[1]<<endl;
            ans.push_back(v[1]-v[0]+1);
        }
        
        return ans;
    }
};
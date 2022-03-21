class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
       // vector<vector<int>> intervals;
        // for(auto p: mp)
        //     intervals.push_back(p.second);
        
        sort(intervals.begin(),intervals.end());
        
        // for(auto v: intervals)
        //     cout<<v[0]<<" "<<v[1]<<endl;
        
        vector<int> cur = intervals[0];
        vector<vector<int>> merged;
        
        for(int i=1; i<intervals.size(); i++)
        {
            auto v = intervals[i];
            if(cur[1] >= v[0])
                cur[1] = max(cur[1],v[1]);
            else{
                merged.push_back(cur);
                cur = v;
            }
        }
        merged.push_back(cur);
        return merged;
    }
};
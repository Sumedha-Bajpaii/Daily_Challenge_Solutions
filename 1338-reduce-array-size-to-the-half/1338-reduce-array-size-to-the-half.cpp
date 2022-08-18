class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<int> freq;
        for(auto p: mp){
            freq.push_back(p.second);
        }
        
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        
        int s=0, cnt=0;
        for(int i=0; i<freq.size(); i++){
            s += freq[i];
            cnt++;
            
            if(s>=n/2)
                return cnt;
        }
        
        return 0;
    }
};
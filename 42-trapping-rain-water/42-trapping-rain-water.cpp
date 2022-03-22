class Solution {
public:
    int trap(vector<int>& h) {
        
        vector<int> l,r;
        int n = h.size();
        int maxi =0;
        for(int i =0;i<n;i++)
        {
            maxi = max(maxi,h[i]);
            l.push_back(max(maxi,h[i]));
        }
        // for(auto i:l)
        //     cout<<i<<" ";
        // cout<<endl;
        
        maxi =0;
        for(int i =n-1;i>=0;i--)
        {
            maxi = max(maxi,h[i]);
            r.push_back(max(maxi,h[i]));
        }
        reverse(r.begin(),r.end());
        
        int sum=0;
        for(int i =0;i<n;i++)
        {
            if(min(l[i],r[i])-h[i]>0)
                sum+=(min(l[i],r[i])-h[i]);
        }
        // for(auto i:r)
        //     cout<<i<<" ";
        // cout<<endl;
        
        return sum;
    }
};
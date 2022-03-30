class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) 
    {
        int r = a.size();
        int c = a[0].size();
        
        int l=0, h=r*c-1, m;
        
        while(l<=h)
        {
            m = (l+h)/2;
            if( a[m/c][m%c] == t)
                return true;
            else if( a[m/c][m%c] > t)
                h = m-1;
            else
                l = m+1;
        }
        return false;
        
    }
};
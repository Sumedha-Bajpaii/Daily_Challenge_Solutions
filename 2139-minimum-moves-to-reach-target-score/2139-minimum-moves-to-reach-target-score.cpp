class Solution {
public:
    int minMoves(int targ, int md) {
        
        if(md==0)
            return targ-1;
        if(targ==1)
            return 0;
        
        if(targ%2 == 0)
            return 1 + minMoves(targ/2, md-1);
        else
            return 1 + minMoves(targ-1, md);
    }
};
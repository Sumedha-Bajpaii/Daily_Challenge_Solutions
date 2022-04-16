class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        int pen=0;
        long long cnt=0;
        
        while(pen*cost1<=total){
            int pencil = (total - pen*cost1)/cost2;
            cnt += (pencil+1);
            pen++;
        }
        return cnt;
    }
};
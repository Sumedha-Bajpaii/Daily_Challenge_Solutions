class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int tank=0, start=0, i=0, n=gas.size(), round=0, visit=0;
        
        while(visit<n){
            if(i==0) round++;
            if(round==3) return -1;
            
            visit++;
            tank += gas[i];
            tank -= cost[i];
            
            if(tank < 0){   //i can not be start
                tank = 0;
                start = (i+1)%n;
                visit=0;
            }
            
            i = (i+1)%n;
        }
        
        return start;
    }
};
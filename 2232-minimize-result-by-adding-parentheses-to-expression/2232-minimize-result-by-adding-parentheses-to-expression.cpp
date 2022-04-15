class Solution {
public:
    string minimizeResult(string exp) {
        
        string num1,num2;
        int ind = exp.find("+");
        num1 = exp.substr(0,ind);
        num2 = exp.substr(ind+1);
        
        int mn=INT_MAX, s1,s2,s3,s4,  x,y;
        for(int i=0; i<num1.size(); i++){
            for(int j=0; j<num2.size(); j++){
                
                if(num1.substr(0,i)=="")
                    s1 = 1;
                else
                    s1 = stoi(num1.substr(0,i));
                    
                
                //int s1 = num1.substr(0,i) ? stoi(num1.substr(0,i)) : 1;
                
                int s2 = stoi(num1.substr(i));
                int s3 = stoi(num2.substr(0,j+1));
              
                //int s4 = num2.substr(j+1) ? stoi(num2.substr(j+1)) : 1;
                
                if(num2.substr(j+1)=="")
                    s4 = 1;
                else
                    s4 = stoi(num2.substr(j+1));
                
                int val = s1 * (s2 + s3) * s4;
                
                if(val < mn){
                    mn = val;
                    x=i; y=j;
                }
            }
        }
        
        //cout<<mn<<" ";
        string res="";
        res = num1.substr(0,x)+"("+num1.substr(x)+"+"+num2.substr(0,y+1)+")"+num2.substr(y+1);
        
        return res;
    }
};
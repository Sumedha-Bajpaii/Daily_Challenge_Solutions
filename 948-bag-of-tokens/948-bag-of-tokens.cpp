class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        //left: score++ power--
        //right: score-- power++
        
        sort(tokens.begin(), tokens.end());
        
        int i=0, j=tokens.size()-1, score=0, ans=0;
        
        while(i<=j){
            
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
            }
            else if(score > 0){
                score--;
                power += tokens[j];
                j--;
            }
            else{
                break;
            }
            ans = max(ans,score);
        }
        
        return ans;
    }
};
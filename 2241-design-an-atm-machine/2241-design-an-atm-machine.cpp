class ATM {
public:
    unordered_map<int,long long> cur;
    unordered_map<int,int> mp;

    ATM() {
        cur = {{20,0},{50,0},{100,0},{200,0},{500,0}};
        mp = {{0,20},{1,50},{2,100},{3,200},{4,500}};
        
        // cout<<"map mp"<<endl;
        // for(auto p: mp){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
    }
    
    void deposit(vector<int> banknotesCount) {
        auto it = mp.begin();
        for(int i=0; i<5; i++){
            cur[mp[i]] += banknotesCount[i];
        }
        // cout<<"map-----cur"<<endl;
        // for(auto p: cur){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
    }
    
    vector<int> withdraw(int amt) {
        vector<int> res(5,0);
        
        for(int i=4; i>=0; i--){
            if(cur[mp[i]]>0 && mp[i]<=amt){
                long long notes = amt/mp[i];
                notes = min(notes,cur[mp[i]]);
                amt -= notes*mp[i];
                cur[mp[i]] -= notes;
                res[i] += notes;
            }
        }
        if(amt==0)
            return res;
        else{
            for(int i=4; i>=0; i--){
                cur[mp[i]] += res[i];
            }
        }
            return {-1};
        }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
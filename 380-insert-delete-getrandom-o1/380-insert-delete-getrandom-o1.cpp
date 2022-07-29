class RandomizedSet {
public:
    // vector<int> v;
    map<int,int> mp;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            // v.push_back(val);
            mp[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int cnt = mp.size();
        int pos = rand()%cnt;
        
        auto it = mp.begin();
        advance(it,pos);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
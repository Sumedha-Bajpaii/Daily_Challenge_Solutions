class MyCalendar {
public:
    unordered_map<int,int> mp;
    set<int> st;
    
    MyCalendar() {
        st.insert(-1);
        mp.insert({-1,0});
        st.insert(1e9+7);
        mp.insert({1e9+7,1e9+7});
    }
    
    bool book(int start, int end) {
        
        if(st.find(start) != st.end())
            return false;
        
        st.insert(start);
        auto it = st.find(start);
        auto pre = prev(it,1);
        auto nex = next(it,1);
        
        if(start>=mp[*pre] && end<=*nex){
            mp[start] = end;
            return true;
        }
        
        st.erase(it);
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
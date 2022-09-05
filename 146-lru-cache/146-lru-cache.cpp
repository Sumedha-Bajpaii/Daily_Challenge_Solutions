class Node{
public:
    int key, val;
    Node *prev, *next;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
    
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap;
    Node *lru, *mru;
    
    LRUCache(int capacity) {
        cap = capacity;
        mru = new Node(-1,-1);
        lru = new Node(-1,-1);
        //mru is head
        //lru is tail
        mru->next = lru;
        lru->prev = mru;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
             return -1;
        Node *temp = mp[key];
        int value = temp->val;      //result
        mp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mp[key] = mru->next;
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *existing = mp[key];
            mp.erase(key);
            deleteNode(existing);
        }
        
        if(mp.size() == cap){
            //delete from LRU side
            mp.erase(lru->prev->key);
            deleteNode(lru->prev);
        }

        addNode(new Node(key,value));
        mp[key] = mru->next;
    }
    
    void addNode(Node *neww){

        Node *temp = mru->next;
        
        neww->next = temp;
        neww->prev = mru;
        temp->prev = neww;
        mru->next = neww;
    }
    
    void deleteNode(Node *x){
        Node *left = x->prev;
        Node *right = x->next;
        
        left->next = right;
        right->prev = left;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
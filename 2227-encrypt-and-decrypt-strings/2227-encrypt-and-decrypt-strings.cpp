class Encrypter {
public:
    unordered_map<char,string> mp;
    vector<string> dict;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0; i<keys.size(); i++){
            mp[keys[i]] = values[i]; 
        }
        dict = dictionary;
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(int i=0; i<word1.size(); i++){
            if(mp.find(word1[i]) != mp.end())
                ans += mp[word1[i]];
            else
                return "";
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int cnt=0;
        for(auto str: dict){
            string s = encrypt(str);
            if(s==word2){
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
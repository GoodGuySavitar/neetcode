class MyHashMap {
public:
    vector<pair<int, int>> hash;
    MyHashMap(){
        
    }
    
    void put(int key, int value) {
        bool done = false;
        for(auto& pair : hash){
            if(pair.first == key){
                pair.second = value;
                done = true;
            }
        }
        if(done){
            return;
        }
        else{
            hash.push_back({key, value});
        }
    }
    
    int get(int key) {
        for(auto pair : hash){
            if(pair.first == key){
                return pair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < hash.size(); ++i){
            if(hash[i].first == key){
                hash.erase(hash.begin() + i);
                return; 
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
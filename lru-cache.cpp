class LRUCache {
public:
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> position;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void used(int key) {
        if(position.count(key)) {
            recent.erase(position[key]);
        } else if(recent.size() >= capacity) {
            int old = recent.back();
            position.erase(old);
            cache.erase(old);
            recent.pop_back();
        }
        recent.push_front(key);
        position[key] = recent.begin();
    }
    
    int get(int key) {
        if(cache.count(key)) {
            used(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        used(key);
        cache[key] = value;
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

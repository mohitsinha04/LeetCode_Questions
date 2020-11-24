class FirstUnique {
public:
    list<int> recent;
    unordered_map<int, list<int>::iterator> position;
​
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(recent.size() > 0){
            return *(recent.begin());
        }else{
            return - 1;
        }
    }
    
    void add(int value) {
        if(!position.count(value)){
            recent.push_back(value);
            auto it = recent.end();
            --it;
            position.insert({value, it});
        }else{
            // remove element from list
            auto it = position[value];
            if(it != recent.end()){
                recent.erase(it);
                position[value] = recent.end();
            }
        }
    }
};
​
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

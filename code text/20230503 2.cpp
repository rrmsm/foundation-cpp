//380. O(1) 时间插入、删除和获取随机元素
class RandomizedSet {
public:
    unordered_map<int, int> m;//无序哈希表
    vector<int> v;
    RandomizedSet() {
        srand((unsigned)time(NULL));//随机种子
    }
    
    bool insert(int val) {
        if(m.count(val) == 0){
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.count(val)){
            int tt = v[v.size() - 1];
            m[tt] = m[val];
            swap(tt, v[m[val]]);
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int i = (rand() % (v.size()));
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
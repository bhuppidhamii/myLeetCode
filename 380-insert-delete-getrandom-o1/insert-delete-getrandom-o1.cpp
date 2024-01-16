class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        v.push_back(val);
        int idx = v.size() - 1;
        m[val] = idx;
        return true;
    }

    // swap val & last_element
    // remove last_element
    // update map
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int idx = m[val];
        int last_element = v.back();

        swap(v[idx], v[v.size()-1]);
        
        m[last_element] = idx;

        v.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
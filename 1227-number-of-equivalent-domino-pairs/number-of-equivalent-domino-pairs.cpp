class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int count = 0;
        for (auto& d : dominoes) {
            vector<int> v = d;
            sort(begin(v), end(v));
            auto p = make_pair(v[0], v[1]);

            if (mp.find(p) != mp.end()) {
                count += mp[p];
            }
            mp[p]++;
        }
        return count;
    }
};
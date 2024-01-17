class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }
        vector<int> v(10001);
        for (auto i : m) {
            v[i.second]++;
            if (v[i.second] > 1) {
                return false;
            }
        }
        return true;
    }
};
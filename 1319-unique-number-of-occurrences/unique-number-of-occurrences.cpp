class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v(2001);
        for (auto i : arr) {
            v[i + 1000]++;
        }
        sort(begin(v), end(v));
        for (int i = 1; i < 2001; i++) {
            if (v[i] != 0 && v[i] == v[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
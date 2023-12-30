class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> m;
        for (auto w : words) {
            for (auto ch : w) {
                m[ch]++;
            }
        }
        int N = words.size();
        for (auto i : m) {
            if (i.second % N != 0) {
                return false;
            }
        }
        return true;
    }
};
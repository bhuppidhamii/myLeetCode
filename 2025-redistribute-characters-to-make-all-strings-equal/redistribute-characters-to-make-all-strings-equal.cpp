class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        for (auto& w : words) {
            for (auto& ch : w) {
                freq[ch - 'a']++;
            }
        }
        int N = words.size();
        for (auto& f : freq) {
            if (f % N != 0) {
                return false;
            }
        }
        return true;
    }
};
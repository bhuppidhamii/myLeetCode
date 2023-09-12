class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        unordered_set<int> freqSet;
        int count = 0;

        for (auto i : m) {
            int freq = i.second;
            while (freq > 0 && freqSet.count(freq)) {
                freq--;
                count++;
            }
            freqSet.insert(freq);
        }

        return count;        
    }
};
class Solution {
public:
    int similarPairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            map<char, int> m;
            for (auto ch : w) {
                m[ch]++;
            }
            string s2 = "";
            for (auto i : m) {
                s2 += i.first;
            }
            words[i] = s2;
        }
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
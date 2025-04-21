class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int> mp;
        for (auto& b : bannedWords) {
            mp[b]++;
        }

        int count = 0;
        for (auto& m : message) {
            if (mp.find(m) != mp.end()) {
                count++;
            }
        }
        return count >= 2 ? true : false;
    }
};
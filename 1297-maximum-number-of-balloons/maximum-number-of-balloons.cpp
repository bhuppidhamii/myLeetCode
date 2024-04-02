class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        for (auto ch : text) {
            m[ch]++;
        }

        string str = "balon";
        vector<pair<char, int>> vp;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'o' || str[i] == 'l') {
                vp.push_back({str[i], m[str[i]] / 2});
            }
            vp.push_back({str[i], m[str[i]]});
        }
        
        int count = INT_MAX;
        for (auto i : vp) {
            if (i.second == 0) {
                return 0;
            }
            count = min(count, i.second);
        }
        return count;
    }
};
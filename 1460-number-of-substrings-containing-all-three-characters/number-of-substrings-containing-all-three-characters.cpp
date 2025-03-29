class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mp;

        int n = s.size(), res = 0;
        int i = 0, j = 0;
        while (j < n) {
            mp[s[j]]++;
            while (mp.size() == 3) {
                if (mp[s[i]] == 1) {
                    mp.erase(s[i]);
                } else {
                    mp[s[i]]--;
                }
                i++;
                res += n - j;
            }
            j++;
        }
        return res;
    }
};
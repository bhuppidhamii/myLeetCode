class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, n = s.size();

        int i = 0;
        int j = 0;

        vector<int> mp(3, 0); // 0->a, 1->b, 2->c
        while (j < n) {
            char ch = s[j];
            mp[ch - 'a']++;

            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                res += n - j;

                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return res;
    }
};
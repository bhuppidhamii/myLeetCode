class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int M = 1e9 + 7;
        // unordered_map<char, int> mp;
        vector<int> mp(26, 0);
        for (auto& ch : s) {
            mp[ch - 'a']++;
        }

        while (t--) {
            // unordered_map<char, int> temp;
            vector<int> temp(26, 0);
            for (int i = 0; i < 26; i++) {
                char ch = i + 'a';
                int freq = mp[i];

                if (ch != 'z') {
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
                } else {
                    temp[0] = temp[0] + freq;
                    temp[1] = temp[1] + freq;
                }
            }
            // mp = move(temp); // temp will empty and transfer to mp;
            mp = move(temp);
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            count = (count + mp[i]%M) % M;
        }
        return count % M;
    }
};
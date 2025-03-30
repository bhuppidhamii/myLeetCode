class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, 0);
        int l = s.size();
        for (int i = 0; i < l; i++) {
            v[s[i] - 'a'] = i; // last index;
        }

        vector<int> res;
        int i = 0, j = 0, end = 0;
        while (j < l) {
            char ch = s[j];
            end = max(end, v[ch - 'a']);

            if (end == j) {
                int p = end - i + 1;
                res.push_back(p);
                i = j + 1;
            }
            j++;
        }
        return res;
    }
};
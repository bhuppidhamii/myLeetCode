class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int N = words.size();
        vector<string> ans;

        for (int i = 0; i < N; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
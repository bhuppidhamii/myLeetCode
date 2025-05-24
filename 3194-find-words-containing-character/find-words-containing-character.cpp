class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int N = words.size();
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            string word = words[i];
            for (auto& ch : word) {
                if (ch == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
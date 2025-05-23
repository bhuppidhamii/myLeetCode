class Solution {
public:
    int N1, N2;
    int lcs(string& word1, string& word2, int i, int j, vector<vector<int>>& t) {
        if (i >= N1 || j >= N2)
            return 0;

        if (t[i][j] != -1) {
            return t[i][j];
        }

        // if chars are same
        if (word1[i] == word2[j]) {
            return t[i][j] = 1 + lcs(word1, word2, i + 1, j + 1, t);
        }

        // if not same
        int move_i = lcs(word1, word2, i + 1, j, t);
        int move_j = lcs(word1, word2, i, j + 1, t);

        return t[i][j] = max(move_i, move_j);
    }
    int minDistance(string word1, string word2) {
        N1 = word1.size();
        N2 = word2.size();
        vector<vector<int>> t(N1 + 1, vector<int>(N2 + 1, -1));
        return N1 + N2 - 2 * lcs(word1, word2, 0, 0, t);
    }
};
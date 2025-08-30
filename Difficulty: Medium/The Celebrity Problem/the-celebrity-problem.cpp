class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> inDegree(n, 0);   // how many know this person
        vector<int> outDegree(n, 0);  // how many this person knows

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    outDegree[i] += 1;  // i knows j
                    inDegree[j] += 1;   // j is known by i
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == n  && outDegree[i] == 1) {
                return i;
            }
        }

        return -1;
    }
};
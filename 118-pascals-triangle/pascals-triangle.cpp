class Solution {
public:
    int nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> arr;
            for (int j = 0; j <= i; j++) {
                arr.push_back(nCr(i, j));
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
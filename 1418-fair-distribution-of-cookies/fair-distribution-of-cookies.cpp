class Solution {
public:
    int result = INT_MAX;
    int n;
    void solve(int idx, vector<int>& childrens, vector<int>& cookies, int k) {
        if (idx >= n) {
            int unfairness = *max_element(begin(childrens), end(childrens));
            result = min(unfairness, result);
            return;
        }

        int cookie = cookies[idx];
        for (int i = 0; i < k; i++) {
            // do
            childrens[i] += cookie;

            // explore
            solve(idx + 1, childrens, cookies, k);

            // undo
            childrens[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> childrens(k, 0);
        n = cookies.size();

        solve(0, childrens, cookies, k);
        return result;
    }
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> v(501, 0);
        for (auto& i : arr) {
            v[i]++;
        }
        int ans = -1;
        for (int i = 1; i < 501; i++) {
            if (i == v[i]) {
                ans = i;
            }
        }
        return ans;
    }
};
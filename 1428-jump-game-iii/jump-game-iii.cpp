class Solution {
public:
    bool solve(vector<int>& arr, int i, vector<bool>& v) {
        if (i < 0 || i >= arr.size() || v[i] == true)
            return false;
        if (arr[i] == 0)
            return true;
        v[i] = true;
        if (solve(arr, i - arr[i], v) || solve(arr, i + arr[i], v)) {
            return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size(), false);
        return solve(arr, start, v);
    }
};
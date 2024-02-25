class Solution {
public:
    bool solve(vector<int>& arr, int i, vector<bool>& v) {
        if (v[i] == true) 
            return false; // return false, if already visted to avoid loop
        if (arr[i] == 0)
            return true;
        v[i] = true; // mark as visited
        bool left = false, right = false; // assume false;
        if (i - arr[i] >= 0 && i - arr[i] < arr.size()) {
            left = solve(arr, i - arr[i], v);
        }
        if (i + arr[i] >= 0 && i + arr[i] < arr.size()) {
            right = solve(arr, i + arr[i], v);
        }
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size(), false);
        return solve(arr, start, v);
    }
};
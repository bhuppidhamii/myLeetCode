class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // Jai Shri Ram
        // BF
        sort(begin(arr), end(arr));
        
        int count = upper_bound(begin(arr), end(arr), x)-begin(arr);
        return count;
    }
};
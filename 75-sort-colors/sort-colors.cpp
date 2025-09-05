class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0;     // --> 0
        int j = 0;     // --> 1
        int k = n - 1; // --> 2

        // perform comparison with 1 idx only - j
        while (j <= k) {
            if (arr[j] == 2) {
                swap(arr[k], arr[j]);
                k--;
            } else if (arr[j] == 0) {
                swap(arr[i], arr[j]);
                j++;
                i++;
            } else {
                j++;
            }
        }
    }
};
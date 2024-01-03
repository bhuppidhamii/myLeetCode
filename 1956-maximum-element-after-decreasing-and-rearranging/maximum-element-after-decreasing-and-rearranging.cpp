class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int onePresent = count(arr.begin(), arr.end(), 1);
        int N = arr.size();
        if (onePresent) {
            sort(arr.begin(), arr.end());
            for (int i = 1; i < N; i++) {
                if (abs(arr[i] - arr[i - 1]) > 1) {
                    arr[i] = arr[i - 1] + 1;
                }
            }
        } else {
            sort(arr.begin(), arr.end());
            arr[0] = 1;
            for (int i = 1; i < N; i++) {
                if (abs(arr[i] - arr[i - 1]) > 1) {
                    arr[i] = arr[i - 1] + 1;
                }
            }
        }
        return arr[N - 1];
    }
};
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int N = arr.size();

        sort(arr.begin(), arr.end());
        arr[0] = arr[0] == 1 ? arr[0] : 1;
        for (int i = 1; i < N; i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr[N - 1];
    }
};
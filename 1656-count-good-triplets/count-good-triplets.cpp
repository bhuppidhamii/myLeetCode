class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int N = arr.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b && 
                        abs(arr[i] - arr[k]) <= c)
                        count++;
                }
            }
        }
        return count;
    }
};
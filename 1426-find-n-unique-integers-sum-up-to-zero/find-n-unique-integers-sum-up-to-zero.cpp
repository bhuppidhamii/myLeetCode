class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);

        int start = 1, i = 0;

        while (i + 1 < n) {
            arr[i] = start;
            arr[i + 1] = -start;

            i += 2;
            start++;
        }
        return arr;
    }
};
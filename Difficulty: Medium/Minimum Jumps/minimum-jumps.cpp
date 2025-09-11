class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Jai Shri Ram
        int n = arr.size();
        if (n == 1) return 0;       // already at last index
        if (arr[0] == 0) return -1; // cannot move anywhere

        int jumps = 0, farthest = 0, end = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);

            // When we reach the end of the current jump range
            if (i == end) {
                jumps++;
                end = farthest;

                if (end >= n - 1) return jumps; // reached last index
            }
        }
        return -1; // can't reach last index
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();

        vector<int> left(N, 0);
        left[0] = height[0];
        int left_max = height[0];
        for (int i = 1; i < N; i++) {
            if (height[i] > left_max) {
                left_max = height[i];
            }
            left[i] = left_max;
        }

        vector<int> right(N, 0);
        right[N - 1] = height[N - 1];
        int right_max = height[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (height[i] > right_max) {
                right_max = height[i];
            }
            right[i] = right_max;
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int mini = min(left[i], right[i]);
            ans += abs(mini - height[i]);
        }
        return ans;
    }
};
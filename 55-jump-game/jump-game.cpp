class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<int> t(N, false);

        // t[i] = true, means i tak pahucha ja sakta h
        // t[i] = false, means i tak nhi pahucha ja sakta h

        t[0] = true; // we can always reach 1st index

        for (int i = 1; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (t[j] == true && j + nums[j] >= i) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[N - 1];
    }
};
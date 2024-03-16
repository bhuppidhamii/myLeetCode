class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 0-> -1
        // 1-> +1

        map<int, int> m;
        // sum,index
        m[0] = -1;

        int N = nums.size();
        int sum = 0, maxLen = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) {
                sum -= 1;
            } else if (nums[i] == 1) {
                sum += 1;
            }

            if (m.find(sum) != m.end()) {
                int idx = m[sum];
                int len = i - idx;
                maxLen = max(maxLen, len);
            } else {
                m[sum] = i;
            }
        }
        return maxLen;
    }
};
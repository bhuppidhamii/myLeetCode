class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj, count = 0;
        int N = nums.size();

        maj = nums[0];
        count = 1;
        for (int i = 1; i < N; i++) {
            if (nums[i] == maj) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    maj = nums[i];
                    count = 1;
                }
            }
        }
        return maj;
    }
};
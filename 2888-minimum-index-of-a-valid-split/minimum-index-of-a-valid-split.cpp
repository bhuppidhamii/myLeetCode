class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> m1;
        map<int, int> m2;
        int L = nums.size();

        for (auto& n : nums) {
            m2[n]++;
        }

        for (int i = 0; i < L; i++) {
            int ele = nums[i];
            int l1 = i + 1, l2 = L - i - 1;
            m1[ele]++;
            m2[ele]--;

            if (m1[ele] > l1 / 2 && m2[ele] > l2 / 2) {
                return i;
            }
        }
        return -1;
    }
};
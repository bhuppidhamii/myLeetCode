class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int N = nums.size();
        if (N % k != 0)
            return false;

        map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }

        for (auto& i : mp) {
            int val = i.first;
            int freq = i.second;

            if (freq == 0)
                continue;

            for (int i = 0; i < k; i++) {
                int nextVal = val + i;

                if (mp[nextVal] < freq) {
                    return false;
                }

                mp[nextVal] -= freq;
            }
        }
        return true;
    }
};
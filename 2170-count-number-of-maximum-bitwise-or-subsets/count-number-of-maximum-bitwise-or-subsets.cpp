class Solution {
public:
    int N;
    void solve(int i, vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& all) {
        if (i >= N) {
            if (temp.size() > 0) {
                all.push_back(temp);
            }
            return;
        }

        // take
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, all);
        temp.pop_back();

        // not-take
        solve(i + 1, nums, temp, all);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        N = nums.size();

        vector<vector<int>> all;
        vector<int> temp;
        solve(0, nums, temp, all);

        int maxi = INT_MIN;
        for (auto& arr : all) {

            int bitwise_or = 0;
            for (auto& i : arr) {
                bitwise_or |= i;
            }
            maxi = max(maxi, bitwise_or);
        }

        int count = 0;
        for (auto& arr : all) {

            int bitwise_or = 0;
            for (auto& i : arr) {
                bitwise_or |= i;
            }
            if (bitwise_or == maxi) {
                count++;
            }
        }
        return count;
    }
};
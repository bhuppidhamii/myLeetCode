class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Jai Shri Ram

        // remove -ve's & duplicates & num == 0
        unordered_map<int, int> mp;
        for (auto& i : nums) {
            if (i > 0) {
                mp[i]++;
            }
        }

        // if all -ve's
        if(mp.size() == 0){
            // return the max -ve element
            return *max_element(nums.begin(), nums.end());
        }

        int sum = 0;
        for (auto& i : mp) {
            sum += i.first;
        }
        return sum;
    }
};
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int N = nums.size();
        int i = 0;
        int j = 0;

        long long count = 0;
        unordered_map<int, int> mp;
        long long pairs = 0;
        
        while (j < N) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while (pairs >= k) {
                count += (N - j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return count;
    }
};
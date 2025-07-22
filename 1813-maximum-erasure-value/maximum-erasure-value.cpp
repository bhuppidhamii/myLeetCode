class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> mp;
        int N = nums.size();
        int i = 0;
        int score = 0, maxScore = INT_MIN;
        for (int j = 0; j < N; j++) {
            mp[nums[j]]++;

            while (i < N && (j - i + 1) > (int)mp.size()) {
                mp[nums[i]]--;
                score -= nums[i];
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            score += nums[j];
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
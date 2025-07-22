class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int>freq(100001, 0);
        int N = nums.size();
        int i = 0, mp_sz = 0;
        int score = 0, maxScore = INT_MIN;
        for (int j = 0; j < N; j++) {
            if(freq[nums[j]] == 0){
                mp_sz++;
            }
            freq[nums[j]]++;

            while (i < N && (j - i + 1) > mp_sz) {
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    mp_sz--;
                }
                score -= nums[i];
                i++;
            }
            score += nums[j];
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
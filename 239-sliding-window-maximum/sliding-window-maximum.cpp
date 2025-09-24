class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Remove out-of-window indices
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            // Collect results once the first window is ready
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
class Solution {
public:
    set<vector<int>> uniqueSubsets; // To store unique subsets

    void solve(vector<int>& nums, int index, vector<int>& currentSubset) {
        if (index == nums.size()) {
            uniqueSubsets.insert(currentSubset);
            return;
        }

        // Include the current element
        currentSubset.push_back(nums[index]);
        solve(nums, index + 1, currentSubset);

        // Exclude the current element
        currentSubset.pop_back();
        solve(nums, index + 1, currentSubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<int> currentSubset;
        solve(nums, 0, currentSubset);

        // Convert set to vector of vectors
        vector<vector<int>> result(uniqueSubsets.begin(), uniqueSubsets.end());
        return result;
    }
};

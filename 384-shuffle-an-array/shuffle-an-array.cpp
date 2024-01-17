class Solution {
public:
    vector<int> og;
    int n;
    Solution(vector<int>& nums) {
        og = nums;
        n = nums.size();
    }

    vector<int> reset() { return og; }

    vector<int> shuffle() {
        vector<int> shuffled = og;

        int leftSize = n;

        for (int i = n - 1; i >= 0; i--) {
            int j = rand() % leftSize;

            swap(shuffled[i], shuffled[j]);
            leftSize--;
        }
        return shuffled;
    }
};
class Solution {
public:
    vector<int>v;
    vector<int>og;
    Solution(vector<int>& nums) {
        v=nums;
        og=nums;
    }
    
    vector<int> reset() {
        return og;
    }
    
    vector<int> shuffle() {
        random_shuffle(v.begin(), v.end());
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
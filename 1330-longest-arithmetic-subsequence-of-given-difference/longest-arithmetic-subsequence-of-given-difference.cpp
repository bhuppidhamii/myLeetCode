class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int maxLen = -1;
        for (auto& i : arr) {
            int currVal = i;
            int prevVal = currVal - k;
            int prevLen = mp[prevVal];
            int currLen = prevLen + 1;
            mp[currVal] = currLen;
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
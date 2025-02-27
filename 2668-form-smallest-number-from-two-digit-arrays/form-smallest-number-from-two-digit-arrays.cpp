class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        int x = nums1[0];
        int y = nums2[0];
        map<int, int> mp;
        for (auto& n : nums1) {
            mp[n]++;
        }
        for (auto& n : nums2) {
            mp[n]++;
        }

        for (auto& i : mp) {
            if (i.second > 1) {
                return i.first;
            }
        }
        return min(x, y) * 10 + max(x, y);
    }
};
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
        vector<vector<int>>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, N1 = nums1.size(), N2 = nums2.size();
        vector<vector<int>> ans;
        while (i < N1 && j < N2) {
            int keyi = nums1[i][0], keyj = nums2[j][0];
            int vali = nums1[i][1], valj = nums2[j][1];
            if (keyi == keyj) {
                ans.push_back({keyi, vali + valj});
                i++, j++;
            } else if (keyi < keyj) {
                ans.push_back({keyi, vali});
                i++;
            } else {
                ans.push_back({keyj, valj});
                j++;
            }
        }
        while (i < N1) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while (j < N2) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
        return ans;
    }
};
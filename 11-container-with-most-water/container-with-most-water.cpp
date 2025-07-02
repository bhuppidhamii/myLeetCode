class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int l = 0, r = N - 1;
        int max_area = -1;
        while (l < r) {
            int len = min(height[l], height[r]);
            int bre = r - l;

            int area = len * bre;
            if (area > max_area) {
                max_area = area;
            }
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};
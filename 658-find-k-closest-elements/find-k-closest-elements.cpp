class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(begin(arr), end(arr), [&x](auto& a, auto& b) {
            if (abs(a - x) == abs(b - x)) {
                return a < b;
            }
            return abs(a - x) < abs(b - x);
        });

        vector<int> ans;
        for (int i = 0; i < arr.size() && k--; i++) {
            ans.push_back(arr[i]);
        }
        
        sort(begin(ans), end(ans));
        return ans;
    }
};
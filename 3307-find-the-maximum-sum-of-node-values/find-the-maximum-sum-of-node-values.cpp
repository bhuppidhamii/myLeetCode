class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0, nuksan = INT_MAX;

        for (ll n : nums) {
            int xr = n ^ k; // xor
            if (xr > n) {
                sum += xr;
                count++;
            } else {
                sum += n;
            }
            nuksan = min(nuksan, (int)abs(n-xr));
        }
        cout << nuksan;
        if (count % 2 == 0) {
            cout << "even";
            return sum;
        }
        return sum - nuksan;
    }
};
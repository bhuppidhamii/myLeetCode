class Solution {
public:
    int N;
    vector<vector<int>> dp;

    int solve(int i, int prev, vector<vector<int>>& pairs) {
        if (i >= N) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        // Option 1: Skip current pair
        int skip = solve(i + 1, prev, pairs);

        // Option 2: Take current pair if valid
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
            take = 1 + solve(i + 1, i, pairs);
        }

        return dp[i][prev + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        N = pairs.size();
        sort(pairs.begin(), pairs.end());

        // prev ranges from -1 to N-1 => size = N+1
        dp = vector<vector<int>>(N, vector<int>(N + 1, -1));

        return solve(0, -1, pairs);
    }
};
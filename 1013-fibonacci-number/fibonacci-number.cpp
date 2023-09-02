class Solution {
private:
    int ans(vector<int>&dp, int n){
        // base case
        if(n==1 || n==0) return n;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n]=ans(dp, n-1) + ans(dp, n-2);
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return ans(dp,n);
    }
};
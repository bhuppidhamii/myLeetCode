class Solution {
  public:
    int solve(int n, vector<int>&dp){
        if(n == 1) return 1;
        if(n <= 0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int maxProd = 0;
        // cout<<"n= "<<n<<"\n";
        for(int i=1; i<n; i++){
            int prod = i * solve(n-i, dp);
            // cout<<prod<<" ";
            maxProd = max(prod, maxProd);
        }
        // cout<<"maxProd = "<<maxProd<<"\n";
        return dp[n] = max(n,maxProd);
    }
    int maxProduct(int n) {
        // Jai Shri Ram
        // recursion
        if(n==2 || n==3) return n-1;
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};
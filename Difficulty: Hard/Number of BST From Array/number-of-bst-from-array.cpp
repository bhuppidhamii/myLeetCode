class Solution {
  public:
    vector<int> computeFact(int n){
        vector<int>fact(n+1);
        fact[0]=1;
        for(int i=1; i<=n; i++){
            fact[i] = fact[i-1]*i;
        }
        return fact;
    }
    
    int catalan(int n, vector<int>&fact){
        return fact[2*n] / (fact[n] * fact[n+1]);
    }
    
    vector<int> countBSTs(vector<int>& arr) {
        // Jai Shri Ram
        
        int n = arr.size();
        vector<vector<int>>sorted;
        for(int i=0; i<n; i++){
            sorted.push_back({arr[i], i});
        }
        
        sort(begin(sorted), end(sorted));
        
        // precompute factorial upto 2*n
        vector<int>fact = computeFact(2*n);
        
        vector<int>ans(n);
        
        for(int i=0; i<n; i++){
            int j=sorted[i][1];
            
            ans[j] = catalan(i, fact) * catalan(n-i-1, fact);
        }
        return ans;
    }
};
class Solution {
public:
    int M = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // create power vector
        vector<int> powers;
        int c = 1;
        while (n > 0) {
            int rem = n % 2;
            if (rem != 0) {
                powers.push_back((rem * c));
            }
            c = (c* 2) % M;
            n = n / 2;
        }
      
        // traverse the queries
        vector<int>ans;
        for(auto &q:queries){
            int start = q[0];
            int end = q[1];
            long prod = 1;
            for(int i=start; i<=end; i++){
                prod = (prod * powers[i])%M;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
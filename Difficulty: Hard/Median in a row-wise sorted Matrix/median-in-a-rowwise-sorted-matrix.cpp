class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // Jai Shri Ram
        vector<int>v;
        for(auto &arr:mat){
            for(auto &i:arr){
                v.push_back(i);
            }
        }
        
        sort(begin(v), end(v));
        
        int N = v.size();
        
       
        // if ()dd
        int idx = 0, idx2= 0;
        if(N%2!=0){
            idx = (N+1)/2;
            return v[idx-1];
        }
        // if even
        idx2 = N/2 +1;
        return (v[idx-1]+v[idx2-1])/2;
    }
};

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // Jai Shri Ram
        int N = arr.size();
        vector<int>v(N+1, 0);
        
        for(auto &i:arr){
            if(i > 0 && i < N+1){
                v[i]++;
            }
        }
        
        for(int i=1; i<N+1; i++){
            if(v[i] == 0){
                return i;
            }
        }
        return N+1;
    }
};
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // Jai Shri Ram
        int N = arr.size();
        int sum = 0;
        for(int i= 0; i<N; i++){
            int occ  = arr[i] * (N-i) * (i+1);
            sum += occ;
        }
        return sum;
    }
};
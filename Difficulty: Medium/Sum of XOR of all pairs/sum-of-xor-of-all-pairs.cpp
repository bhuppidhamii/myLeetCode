class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // Jai Shri Ram
        int n= arr.size();
        long long sum = 0;
        for(int i=0; i<32; i++){
            long long zero_count=0, one_count=0;
            for(int j=0; j<n; j++){
                if(arr[j] % 2 == 0){
                    zero_count++;
                }else{
                    one_count++;
                }
                arr[j]/=2;
            }
            long long total_pairs = one_count * zero_count;
            sum+=((total_pairs)*pow(2,i));
        }
        return sum;
    }
};
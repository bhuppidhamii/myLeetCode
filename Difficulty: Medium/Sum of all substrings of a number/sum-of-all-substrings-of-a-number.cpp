class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int N = s.size();
        int sum=0;
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                string str=s.substr(i, j-i+1);
                int n=stoi(str);
                sum+=n;
            }
        }
        return sum;
    }
};
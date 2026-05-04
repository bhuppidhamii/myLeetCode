class Solution {
  public:
    int isPallindrome(long long int N) {
        // Jai Shri Ram
        string s="";
        while(N > 0){
            int rem = N%2;
            s+=to_string(rem);
            N/=2;
        }
        // cout<<N;
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
};
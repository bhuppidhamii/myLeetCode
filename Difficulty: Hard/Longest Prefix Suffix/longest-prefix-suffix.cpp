class Solution {
  public:
    int getLPSLength(string &s) {
        // Jai Shri Ram
        
        int len = 0;
        int N = s.size();
        
        vector<int>LPS(N, 0);
        int i=1;
        while(i < N){
            if(s[i] == s[len]){
                len++;
                LPS[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = LPS[len-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return LPS[N-1];
    }
};
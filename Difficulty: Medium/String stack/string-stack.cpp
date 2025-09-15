class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // Jai Shri Ram
        
        int n = pat.size(), m =  tar.size();
        int i = n-1, j = m-1;
        
        string s = "";
        
        while(i >= 0  && j >= 0){
            if(pat[i] == tar[j]){
                s+=pat[i];
                i--, j--;
            }else{
                // if not equal -> add pat[i] 
                // then remove pat[i] in next ops
                i-=2;
            }
        }
        if(j >= 0) return false;
        return true;
    }
};
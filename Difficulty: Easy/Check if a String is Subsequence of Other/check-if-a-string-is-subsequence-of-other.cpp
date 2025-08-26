class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // Jai Shri Ram
        int L1 = s1.size();
        int L2 = s2.size();
        
        int i=0, j=0;
        
        while(i<L1 && j<L2){
            if(s1[i] == s2[j]){
                i++,j++;
            }else{
                j++;
            }
        }
        return i == L1;
    }
};
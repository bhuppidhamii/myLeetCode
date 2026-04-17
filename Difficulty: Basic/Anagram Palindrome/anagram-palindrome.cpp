class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // Jai Shri Ram
        vector<int>freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
        
        // check frequency
        int oddCount = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2!=0){
                oddCount++;
                if(oddCount > 1) return false;
            }
        }
        return true;
    }
};
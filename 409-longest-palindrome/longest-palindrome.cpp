class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
        int oddCount = 0;
        for(auto &ch : s){
            mp[ch]++;
            if(mp[ch]%2 == 1){
                oddCount++;
            }else{
                oddCount--;
            }
        }

        int N = s.size();
        int evenCount = N - oddCount;
        int result = evenCount;
        if(oddCount > 0){
            result++;
        }
        return result;
    }
};
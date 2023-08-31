class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(auto ch:s){
            m[ch]++;
        }
        int count=0;
        bool odd=false;
        for(auto i:m){
            if(i.second % 2 == 0){
                count += i.second;
            }else{
                count += i.second - 1;
                odd = true;
            }
        }
        
        if(odd){
            return count+1;
        }else{
            return count;
        }
    }
};
class Solution {
public:
    string reversePrefix(string word, char ch) {
       int N=word.length();
       int idx=word.find(ch);
       string one=word.substr(0,idx+1);
       reverse(one.begin(),one.end());
       string two=word.substr(idx+1);
       return one+two;
    }
};
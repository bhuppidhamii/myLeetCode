class Solution {
public:
    bool isSubsequence(string &word, string &s){
        int N=word.size(), M=s.size();
        int i=0, j=0;

        while(i<N && j<M){
            if(word[i] == s[j]){
                i++, j++;
            }else{
                j++;
            }
        }
        if(i == N) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(),[](auto &a, auto &b){
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() > b.size();
        });

        for(auto &word:d){
            if(isSubsequence(word, s)){
                return word;
            }
        }
        return "";
    }
};
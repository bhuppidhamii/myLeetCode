class Solution {
public:
    int stringTointeger(string &str){
      string intStr="";
      for(auto ch:str){
        int n=ch-'a';
        intStr+=to_string(n);
      }
      cout<<intStr<<endl;
      int res=stoi(intStr);
      return res;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1=stringTointeger(firstWord);
        int n2=stringTointeger(secondWord);
        int n3=stringTointeger(targetWord);
        return n1+n2==n3;
    }
};
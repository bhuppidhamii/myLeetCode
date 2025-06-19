class Solution {
  public:
    string caseSort(string& s) {
        // Jai Shri Ram
        vector<char>uprCase;
        vector<int>uprPos;
        
        vector<char>lwrCase;
        vector<int>lwrPos;
        
        int N = s.size();
        for(int i=0; i<N; i++){
            if(s[i]>='a' && s[i] <='z'){
                lwrPos.push_back(i);
                lwrCase.push_back(s[i]);
            }else{
                uprPos.push_back(i);
                uprCase.push_back(s[i]);
            }
        }
        sort(uprCase.begin(), uprCase.end());
        sort(lwrCase.begin(), lwrCase.end());
        
        vector<char>ans(N,'a');
        
        int U=uprCase.size();
        for(int i=0;i<U;i++){
            ans[uprPos[i]]=uprCase[i];
        }
        
        int L=lwrCase.size();
        for(int i=0;i<L;i++){
            ans[lwrPos[i]]=lwrCase[i];
        }
        
        string str="";
        for(auto &ch:ans){
            str+=ch;
        }
        return str;
    }
};
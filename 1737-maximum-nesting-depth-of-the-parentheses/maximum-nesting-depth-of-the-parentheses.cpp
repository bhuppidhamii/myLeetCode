class Solution {
public:
    int maxDepth(string s) {
        int maxi=-1, curr=0;
        for(auto ch:s){
          if(ch=='('){
            curr++;
          }else if(ch==')'){
            curr--;
          }
          maxi=max(maxi,curr);
        }
        return maxi;
    }
};
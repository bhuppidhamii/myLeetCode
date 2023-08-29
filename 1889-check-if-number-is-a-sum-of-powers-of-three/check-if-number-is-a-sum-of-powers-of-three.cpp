class Solution {
private:
    string TernaryRep(int n){
        string ans="";
        while(n>0){
            int rem=n%3;
            ans=to_string(rem)+ans;
            n=n/3;
        }
        return ans;
    }
public:
    bool checkPowersOfThree(int n) {
        string ternary=TernaryRep(n);
        if(ternary.find('2')==string::npos){
            return true;
        }else{
            return false;
        }
    }
};
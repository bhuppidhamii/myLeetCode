class Solution {
public:
    bool checkFreq(string &s){ 
        // check if any char has freq 2
        map<char,int>m;
        for(auto ch:s){
            m[ch]++;
        }
        for(auto i:m){
            if(i.second>=2){
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        if(s==goal){
            if(checkFreq(s)){
                return true;
            }else{
                return false;
            }
        }else{
            // kon konse indices hai jaha s ka char!=gaol ka char 
            // sirf 2 indexes not equal hone chahiye
            vector<int>idx;
            for(int i=0;i<s.length();i++){
                if(s[i]!=goal[i]){
                    idx.push_back(i);
                }
            }
            if(idx.size()==2){
                swap(s[idx[0]],s[idx[1]]);
                if(s==goal){
                    return true;
                }
            }
        }
        return false;
    }
};
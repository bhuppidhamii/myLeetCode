class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>m1;
        for(auto i:chars){
            m1[i]++;
        }

        string ans="";
        for(auto word:words){
            map<char,int>m2;
            for(auto ch:word){
                m2[ch]++;
            }

            bool insert=true;
            for(auto ch:word){
                if( !(m2[ch] <= m1[ch])){
                    insert=false;
                    break;
                }
            }
            if(insert) ans+=word;
        }
        return ans.size();
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=-1;
        if(haystack.find(needle)!=string::npos){
            return haystack.find(needle);
        }else{
            return idx;
        }
    }
};
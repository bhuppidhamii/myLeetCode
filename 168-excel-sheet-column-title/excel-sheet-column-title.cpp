class Solution {
public:
    string convertToTitle(int cn) {
        // if(cn < 27){
        //     char ch ='A'+ (cn-1) % 26;
        //     return ch+"";
        // }
        string res="";
        while(cn>0){
            char ch='A'+ (cn-1) % 26;
            res=ch+res;
            cn=(cn-1)/26;
        }
        return res;
    }
};
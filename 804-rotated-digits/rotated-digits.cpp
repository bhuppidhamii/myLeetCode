class Solution {
public:
    bool goodNumber(int n){
        string s=to_string(n);
        // cout<<s<<"-";
        string new_no="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='3' || s[i]=='4' || s[i]=='7') return false;
            if(s[i]=='2'){
                new_no+='5';
            }else if(s[i]=='5'){
                new_no+='2';
            }else if(s[i]=='6'){
                new_no+='9';
            }else if(s[i]=='9'){
                new_no+='6';
            }else{
                new_no+=s[i];
            }
        }
        // cout<<s<<"-"<<new_no;
        return s!=new_no ? true : false;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++){
            if(goodNumber(i)==true){
                count++;
            }
        }
        return count;
    }
};
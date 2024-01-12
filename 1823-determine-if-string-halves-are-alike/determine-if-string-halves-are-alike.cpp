class Solution {
private:
    int countVowels(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                c++;
            }
        }
        return c;
    }
public:
    bool halvesAreAlike(string s) {
       int l=s.size();
       string a=s.substr(0,l/2);
       string b=s.substr(l/2);
       cout<<a<<" "<<b;

       if(countVowels(a)==countVowels(b)){
           return true;
       }
       return false;
    }
};
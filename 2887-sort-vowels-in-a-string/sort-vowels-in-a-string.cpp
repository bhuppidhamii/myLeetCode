class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='u' ||ch=='o' ||ch=='i' ||ch=='e' ){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        for(auto &ch:s){
            if(isVowel(tolower(ch))){
                vowels.push_back(ch);
            }
        }
        
        if(vowels.size() == 0) return s;
        sort(vowels.begin(), vowels.end());
        
        int N = s.size();
        int idx = 0;
        for(int i=0; i<N; i++){
            char ch = s[i];
            if(isVowel(tolower(ch))){
                s[i] = vowels[idx++];
            }
        }
        return s;
    }
};
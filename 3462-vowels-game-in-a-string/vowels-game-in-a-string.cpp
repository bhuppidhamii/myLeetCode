class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int countVowels = 0;
        for(auto &ch:s){
            if(isVowel(ch)) countVowels++;
        }
        
        if(countVowels == 0) return false; 
        // no vowels are there for alice to remove

        if(countVowels % 2 != 0) return true; 
        // alice remove complete string 
        // as it contains odd no of vowels
        
        if(countVowels % 2 == 0) return true; 
        // here, also, Alice win because she would remove the maximum odd number 
        // of vowels & after removing the vowels, Only odd number of vowels will 
        // be left, so Bob can't win.
        
        return false;
    }
};
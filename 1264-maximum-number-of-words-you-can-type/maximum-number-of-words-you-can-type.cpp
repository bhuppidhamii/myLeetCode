class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // map to quickly access all broken letters
        unordered_map<char,int>mp;
        for(auto &ch:brokenLetters){
            mp[ch]++;
        }

        // string stream
        stringstream ss(text);
        string word;
        int count = 0;
        while(ss >> word){
            
            bool possible = true;
            for(auto &ch:word){
                if(mp.find(ch) != mp.end()){
                    possible = false;
                    break;
                }
            }

            if(possible) count++;
        }
        return count;;
    }
};
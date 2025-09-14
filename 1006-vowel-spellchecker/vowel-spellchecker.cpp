class Solution {
public:
    bool isVowel(char& ch) {
        char c = tolower(ch);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    string toLowerCase(string& word) {
        string ans = "";
        for (auto& w : word) {
            ans += tolower(w);
        }
        return ans;
    }
    string vowelError(string& word) {
        string s = "";
        for (auto& w : word) {
            if (isVowel(w)) {
                s += "*";
            } else {
                s += tolower(w);
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> mp;
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> vowelMap;
        for (auto& word : wordlist) {
            // push exact word
            mp[word]++;

            // push word - all lowercase
            string str = toLowerCase(word);
            lowerMap.insert({str, word});

            // push word - all vowels -> *
            string s = vowelError(word); 
            vowelMap.insert({s, word});
        }

        vector<string> ans;
        for (auto& q : queries) {
            // 1. exact match
            if (mp.find(q) != mp.end()) {
                ans.push_back(q);
                continue;
            }

            // 2. capitalization error
            string str = toLowerCase(q);
            if (lowerMap.find(str) != lowerMap.end()) {
                ans.push_back(lowerMap[str]);
                continue;
            }

            // 3. Vowel Error
            string s = vowelError(q);
            if (vowelMap.find(s) != vowelMap.end()) {
                ans.push_back(vowelMap[s]);
                continue;
            }

            // 4. No match found
            ans.push_back("");
        }
        return ans;
    }
};
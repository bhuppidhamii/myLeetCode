class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        map<char, char> mp1;
        
        for (int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end() && mp1.find(t[i]) != mp1.end()){
                return false;
            }
            if (mp.find(s[i]) == mp.end()) { // if not present
                mp[s[i]] = t[i];
                mp1[t[i]] = s[i];
            } else {
                // if present

                // map to correct
                if (mp[s[i]] == t[i]) {
                    continue;
                } else {
                    // map to others
                    return false;
                }
            }
        }
        return true;
    }
};
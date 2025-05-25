class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;
        for (auto& w : words) {
            string reversedWord = w;
            swap(reversedWord[0], reversedWord[1]);

            if (mp[reversedWord] > 0) { // if reversed word present in map
                result += 4;
                mp[reversedWord]--;
                if (mp[reversedWord] == 0) {
                    mp.erase(reversedWord);
                }
            } else {
                mp[w]++;
            }
        }

        // check of equal characters
        for (auto& i : mp) {
            string str = i.first;
            if (str[0] == str[1]) {
                result += 2;
                break;
            }
        }
        return result;
    }
};
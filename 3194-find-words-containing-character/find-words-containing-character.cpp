class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int N = words.size();
        //   -------  lambda capture, characters
        auto lambda = [&x](char ch) { 
            return (ch == x); 
        };

        for (int i = 0; i < N; i++) {
            string word = words[i];
            if( any_of(begin(word), end(word), lambda ) == true) { 
                ans.push_back(i); 
            }
        }
        return ans;
    }
};
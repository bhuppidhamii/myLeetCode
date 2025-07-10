class Solution {
public:
    string longestString(vector<string>& arr) {
        sort(arr.begin(), arr.end()); // Sort lexicographically
        unordered_set<string> valid;
        valid.insert(""); // base case
        string res = "";

        for (string& word : arr) {
            string prefix = word.substr(0, word.length() - 1);
            // cout<<prefix<<" ";
            if (valid.count(prefix)) { // if prefix is present in set
                valid.insert(word);
                // cout<<word<<"\n";
                if (word.size() > res.size()) {
                    res = word;
                }else if(word.size() == res.size()){
                    res = min(res, word);
                }
            }
        }
        return res;
    }
};
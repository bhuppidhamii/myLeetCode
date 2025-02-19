class Solution {
public:
    void solve(vector<string>& result, string& curr, int n) {
        if (curr.size() == n) { // happy string found
            result.push_back(curr);
            return;
             
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) {
                continue;
            }

            // do -------
            curr.push_back(ch);

            // explore ------
            solve(result, curr, n);

            // undo ------
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> result;
        string curr = "";

        solve(result, curr, n);
        if (k > result.size())
            return "";
        return result[k - 1];
    }
};
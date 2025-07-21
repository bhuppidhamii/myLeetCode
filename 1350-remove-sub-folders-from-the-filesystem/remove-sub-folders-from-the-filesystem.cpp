class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        set<string> st(folder.begin(), folder.end());
        vector<string> ans;
        for (auto& f : folder) {
            string str = f;
            bool found = false;
            while (true) {
                int idx = str.find_last_of('/');
                if (idx == string::npos) break;

                if (idx != string::npos) {
                    string sub = str.substr(0, idx);
                    if (st.find(sub) != st.end()) { // found in set
                        found = true;
                        break;
                    } else {
                        str = sub;
                    }
                }
            }
            if (found == false) {
                ans.push_back(f);
            }
        }
        return ans;
    }
};
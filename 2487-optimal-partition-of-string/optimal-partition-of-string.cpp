class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        set<char> st;
        for (auto& ch : s) {
            if (st.count(ch)) {
                count++;
                st.clear();
            }
            st.insert(ch);
        }
        return count;
    }
};
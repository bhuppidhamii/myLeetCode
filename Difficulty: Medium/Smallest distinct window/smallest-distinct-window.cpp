//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        set<char> st(begin(str), end(str));
        int k = st.size();  // Total unique characters

        int N = str.size();
        int i = 0, j = 0;
        map<char, int> mp;
        int res = INT_MAX;

        while (j < N) {
            mp[str[j]]++;

            while (mp.size() == k && i <= j) {
                res = min(res, j - i + 1);  // Fix here: window size
                mp[str[i]]--;
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
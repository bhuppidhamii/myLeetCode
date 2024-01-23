class Solution {
public:
    unordered_map<string,int>m;
    bool hasDuplicate(string s1, string s2) {
        int arr[26] = {0};
        for (auto s : s1) {
            arr[s - 'a']++;
            if (arr[s - 'a'] > 1) {
                return true;
            }
        }
        for (auto s : s2) {
            arr[s - 'a']++;
            if (arr[s - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }
    int n;
    int solve(vector<string>& arr, string temp, int i) {
        if (i >= n) {
            return 0;
        }

        int include = 0;
        int exclude = 0;

        if(m.find(temp)!=m.end()){ //already found
            return m[temp];
        }

        if (hasDuplicate(temp, arr[i])) { // exclude only
            exclude = solve(arr, temp, i + 1);
        } else {
            exclude = solve(arr, temp, i + 1);
            include = arr[i].size() + solve(arr, temp + arr[i], i + 1);
        }
        return m[temp]=max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        m.clear();
        n = arr.size();
        string temp = "";
        return solve(arr, temp, 0);
    }
};
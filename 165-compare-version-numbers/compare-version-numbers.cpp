class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);

        stringstream ss2(version2);

        string word1, word2;
        while (ss1.good() || ss2.good()) {
            if (!getline(ss1, word1, '.')) word1 = "0";
            if (!getline(ss2, word2, '.')) word2 = "0";
            
            int n1 = stoi(word1);
            int n2 = stoi(word2);

            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
        }
        return 0;
    }
};
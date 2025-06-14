class Solution {
public:
    int minMaxDifference(int num) {
        // find maximum number --------

        string str1 = to_string(num);
        // find the 1st index of char, which is not '9'
        int idx1 = str1.find_first_not_of('9');

        if (idx1 != string::npos) {
            char ch = str1[idx1];

            // replace every occurance of ch with '9'
            replace(str1.begin(), str1.end(), ch, '9');
        }
        int maxi = stoi(str1);

        // find minimum number --------
        string str2 = to_string(num);
        // find the 1st index of char, which is not '0
        int idx2 = str2.find_first_not_of('0');

        if (idx2 != string::npos) {
            char ch = str2[idx2];

            // replace every occurence of ch wiht '0'
            replace(str2.begin(), str2.end(), ch, '0');
        }
        int mini = stoi(str2);

        return maxi - mini;
    }
};
class Solution {
public:
    bool isSpecialCharacter(char c) {
        return !isalpha(c) && !isdigit(c) && !isspace(c);
    }

    bool strongPasswordCheckerII(string p) {
        int N = p.size();
        if (N < 8)
            return false;
        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool specialChar = false;

        int i = 0;
        for (int i = 0; i < N - 1; i++) {
            if (p[i] == p[i + 1])
                return false;

            char ch = p[i];
            if (islower(ch)) {
                lowercase = true;
            } else if (isupper(ch)) {
                uppercase = true;
            } else if (isdigit(ch)) {
                digit = true;
            } else if (isSpecialCharacter(ch)) {
                specialChar = true;
            }

            // check last char ------->
            ch = p[N - 1];
            if (islower(ch)) {
                lowercase = true;
            } else if (isupper(ch)) {
                uppercase = true;
            } else if (isdigit(ch)) {
                digit = true;
            } else if (isSpecialCharacter(ch)) {
                specialChar = true;
            }
        }

        return uppercase && lowercase && digit && specialChar;
    }
};
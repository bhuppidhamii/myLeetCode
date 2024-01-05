class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());

        string str1 = "", str2 = "";
        for (int i = 0; i < str.size(); i++) {
            if (i % 2 == 0) {
                str1 += str[i];
            } else {
                str2 += str[i];
            }
        }
        cout << str1 << " " << str2;

        int num1 = stoi(str1);
        int num2 = stoi(str2);
        return num1 + num2;
    }
};
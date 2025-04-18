class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        if (N == 1)
            return 1;

        int idx = 0, i = 0;
        while (i < N) {
            char curr_char = chars[i];
            int count = 0;

            while (i < N && curr_char == chars[i]) {
                count++;
                i++;
            }

            chars[idx++] = curr_char;
            if (count > 1) {
                string str = to_string(count);
                for (auto& ch : str) {
                    chars[idx++] = ch;
                }
            }
        }
        return idx;
    }
};
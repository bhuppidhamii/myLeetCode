class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            int len = to_string(i).size();
            if (len % 2 == 0) {
                string str = to_string(i);
                int sum_front = 0;
                for (int j = 0; j < len / 2; j++) {
                    sum_front += str[j] - '0';
                }

                int sum_back = 0;
                for (int k = len - 1; k >= len / 2; k--) {
                    sum_back += str[k] - '0';
                }

                if (sum_front == sum_back) {
                    count++;
                }
            }
        }
        return count;
    }
};
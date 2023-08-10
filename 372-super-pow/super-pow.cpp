class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 1) {
            return 1;
        }

        int base = a % 1337; // Reduce the base modulo 1337
        int exponent = 0;
        for (auto i : b) {
            exponent = (exponent * 10 + i) % 1140; 
            // Euler's Totient Function of 1337 is 1140
        }

        int result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % 1337;
            }
            base = (base * base) % 1337;
            exponent /= 2;
        }

        return result;
    }
};

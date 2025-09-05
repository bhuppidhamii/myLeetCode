class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        int t = 0;
        while(true){
            long long val = (long long)num1 - (long long)t*num2;
            if(val < 0) return -1;
            int min_bits = __builtin_popcountll(val);
            if(min_bits <= t && t <= val) {
                return t;
            }
            t++;
        }
        return -1;
    }
};
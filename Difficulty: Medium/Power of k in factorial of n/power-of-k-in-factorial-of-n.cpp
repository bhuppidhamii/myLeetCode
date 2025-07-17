class Solution {
  public:
    // Prime factorization of k
    map<int, int> primeFactorize(int k) {
        map<int, int> pf;
        for (int i = 2; i * i <= k; i++) {
            while (k % i == 0) {
                pf[i]++;
                k /= i;
            }
        }
        if (k > 1) pf[k]++;
        return pf;
    }
    
    // Count of prime p in n!
    int countInFactorial(int n, int p) {
        int count = 0;
        while (n > 0) {
            n /= p;
            count += n;
        }
        return count;
    }
    
    int maxPowerKInFactorial(int n, int k) {
        auto pf = primeFactorize(k);
        int ans = INT_MAX;
        for (auto &i : pf) {
            int p = i.first;
            int freq = i.second;
            int cnt = countInFactorial(n, p);
            ans = min(ans, cnt / freq);
        }
        return ans;
    }
    
    int maxKPower(int n, int k) {
        return maxPowerKInFactorial(n,k);
    }
};
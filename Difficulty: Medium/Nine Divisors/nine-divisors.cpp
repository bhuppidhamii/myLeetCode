class Solution {
  public:
    int countNumbers(int n){
    int c = 0;
    int limit = sqrt(n);

    int prime[limit + 1];
    for (int i = 1; i <= limit; i++)
        prime[i] = i;

    // Sieve to store smallest prime factor
    for (int i = 2; i * i <= limit; i++) {
        if (prime[i] == i) {
            for (int j = i * i; j <= limit; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    }

    for (int i = 2; i <= limit; i++) {
        int p = prime[i];
        int q = prime[i / prime[i]];

        // Check for p^2 * q^2 form
        if (p * q == i && q != 1 && p != q) {
            c += 1;
        }
        
        // Check for p^8 form
        else if (prime[i] == i && pow(i, 8) <= n) {
            c += 1;
        }
    }

        return c;
    }
};
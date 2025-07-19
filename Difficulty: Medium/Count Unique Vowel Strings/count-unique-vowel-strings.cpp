class Solution {
  public:
    bool isVowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i) res *= i;
        return res;
    }

    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            if (isVowel(ch)) freq[ch]++;
        }

        int uniqueVowelCount = freq.size();
        if (uniqueVowelCount == 0) return 0;

        int totalChoices = 1;
        for (auto& i: freq) {
            int count = i.second;
            totalChoices *= count;
        }

        return totalChoices * factorial(uniqueVowelCount);
    }
};
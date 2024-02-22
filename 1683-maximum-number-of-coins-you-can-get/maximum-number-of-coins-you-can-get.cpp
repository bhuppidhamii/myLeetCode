class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), end(piles), [&](auto a, auto b) { 
            return a > b; 
        });
        for (auto i : piles) {
            cout << i << " ";
        }
        int n=piles.size();
        int i=1,j=n-1;

        int sum=0;
        while(i<j){
            sum+=piles[i];
            i+=2;
            j--;
        }
        return sum;
    }
};
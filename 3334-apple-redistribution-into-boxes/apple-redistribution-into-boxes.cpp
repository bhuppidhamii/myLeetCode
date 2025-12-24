class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(begin(apple), end(apple), 0);

        // sort capacity in decending order
        sort(begin(capacity), end(capacity),[](auto &a, auto &b){
            return a>b;
        });

        int i=0;
        while(totalApples > 0){
            totalApples-=capacity[i];
            i++;
        }
        return i;
    }
};
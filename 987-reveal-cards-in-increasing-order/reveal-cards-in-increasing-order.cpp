class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int N = deck.size();
        vector<int> ans(N);
        sort(deck.begin(), deck.end());

        for (int i = 0; i < N; i++) {
            q.push(i);
        }

        for (int i = 0; i < N; i++) {
            ans[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
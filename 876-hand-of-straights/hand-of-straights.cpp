class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();

        map<int, int> mp;
        for (auto& i : hand) {
            mp[i]++;
        }

        for (auto& i : mp) {
            int val = i.first;
            int freq = i.second;
            
            if(freq == 0) continue;

            for (int i = 0; i < groupSize; i++) {
                int nextValue = val + i;

                mp[nextValue] -= freq;

                if (mp[nextValue] < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
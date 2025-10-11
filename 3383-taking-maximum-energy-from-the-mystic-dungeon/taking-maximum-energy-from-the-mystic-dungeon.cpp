class Solution {
public:

    int solve(vector<int>& energy, int k, int idx, vector<int>&t) {
        if (idx >= energy.size()) return 0;

        if(t[idx] != -1) return t[idx];

        return t[idx] = energy[idx] + solve(energy, k, idx + k, t);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>t(n,-1);
        int max_energy = INT_MIN;
        for (int i = 0; i < n; i++) {

            // check from every index
            max_energy = max(max_energy, energy[i] + solve(energy, k, i + k, t));
        }
        return max_energy;
    }
};
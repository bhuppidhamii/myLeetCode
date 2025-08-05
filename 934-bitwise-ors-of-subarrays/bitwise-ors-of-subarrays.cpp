class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> result;

        for (auto& a : arr) {

            unordered_set<int> curr;
            for (auto& p : prev) {
                curr.insert(a | p);
                result.insert(a | p);
            }
            // insert a
            curr.insert(a);
            result.insert(a);

            prev = curr;
        }
        return result.size();
    }
};
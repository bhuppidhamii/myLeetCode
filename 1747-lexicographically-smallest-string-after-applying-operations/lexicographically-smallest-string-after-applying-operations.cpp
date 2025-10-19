class Solution {
public:
    string rotate(string& curr, int b) {
        reverse(begin(curr), end(curr));
        reverse(begin(curr), begin(curr) + b);
        reverse(begin(curr) + b, end(curr));

        return curr;
    }
    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        queue<string> q;
        q.push(s);

        unordered_set<string> visited;
        visited.insert(s); // mark as visited

        while (q.size() > 0) {
            string curr = q.front();
            q.pop();

            if (curr < smallestString) {
                smallestString = curr;
            }

            // add by a in odd indices
            string temp = curr;
            for (int i = 1; i < temp.size(); i += 2) {
                temp[i] = ((temp[i] - '0' + a) % 10 + '0');
            }

            // if temp is not present in set, then only proceed forward
            if (visited.find(temp) == visited.end()) {
                visited.insert(temp);
                q.push(temp);
            }

            // rotate right by b
            string temp2 = rotate(curr, b);
            if (visited.find(temp2) == visited.end()) {
                visited.insert(temp2);
                q.push(temp2);
            }
        }
        return smallestString;
    }
};
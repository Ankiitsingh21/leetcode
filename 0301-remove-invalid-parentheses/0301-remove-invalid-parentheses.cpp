class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;

                // More closing brackets than opening brackets
                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                // If valid, add it to answer
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // If we already found valid strings at this level,
                // don't generate strings with more removals.
                if (found)
                    continue;

                // Try removing every parenthesis
                for (int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses, not letters
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Valid strings were found with minimum removals
            if (found)
                break;
        }

        return ans;
    }
};
class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }
        unordered_map<char, int> used;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]--;
            if (used[s[i]])
                continue;
            while (!st.empty() && st.top() > s[i] && mpp[st.top()] > 0) {
                used[st.top()] = false;
                st.pop();
            }
            used[s[i]] = true;
            st.push(s[i]);
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
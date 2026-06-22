class Solution {
public:
    int maxNumberOfBalloons(string s) {
        string target = "balloon";
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }
        unordered_map<char, int> freq;
        for (char c : target) {
            freq[c]++;
        }
        int ans = INT_MAX;
        for (auto [c, cnt] : freq) {
            ans = min(ans, mpp[c] / freq[c]);
        }
        return ans;
    }
};
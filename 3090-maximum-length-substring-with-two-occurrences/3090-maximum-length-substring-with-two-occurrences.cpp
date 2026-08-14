class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        // map<char, int> fre  q;
        vector<int> freq(256);
        int ans = INT_MIN;
        while (r < s.size()) {
            freq[s[r]]++;
            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
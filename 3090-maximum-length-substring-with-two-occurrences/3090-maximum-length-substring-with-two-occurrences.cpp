class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        map<char, int> mpp;
        int ans = INT_MIN;
        while (r < s.size()) {
            mpp[s[r]]++;
            while (mpp[s[r]] > 2) {
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
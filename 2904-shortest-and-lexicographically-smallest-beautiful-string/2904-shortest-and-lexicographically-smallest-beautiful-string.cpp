class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0;
        // map<int,int> mpp;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";
        while (r < s.size()) {
            if (s[r] == '1') {
                ones++;
            }
            while (ones > k) {
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }
            if (ones == k) {
                while (s[l] == '0') {
                    l++;
                }
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(l, len);
                } else if (len == minLen) {
                    string curr = s.substr(l, len);
                    if (curr < ans) {
                        ans = curr;
                    }
                }
            }
            r++;
        }
        return ans;
    }
};
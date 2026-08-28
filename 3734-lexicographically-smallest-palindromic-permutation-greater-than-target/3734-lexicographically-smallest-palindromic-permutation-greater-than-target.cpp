class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        // Count characters.
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // A palindrome is possible only if at most one character
        // has odd frequency.
        int oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (oddChar != -1) return "";
                oddChar = i;
            }
        }

        // Counts available for the left half.
        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // Construct palindrome from a left half.
        auto makePalindrome = [&](const string& left) {
            string res = left;

            if (n % 2) {
                res += char('a' + oddChar);
            }

            string rev = left;
            reverse(rev.begin(), rev.end());
            res += rev;

            return res;
        };

        // ------------------------------------------------------------
        // First, check whether target's left half can be formed exactly.
        // ------------------------------------------------------------
        vector<int> rem = halfCnt;
        bool exactPossible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                exactPossible = false;
                break;
            }

            rem[x]--;
        }

        // If target's left half is exactly possible, then the palindrome
        // formed from it is the smallest palindrome with that left half.
        if (exactPossible) {
            string left = target.substr(0, m);
            string pal = makePalindrome(left);

            if (pal > target) {
                return pal;
            }
        }

        // ------------------------------------------------------------
        // Now find the smallest left half > target's left half.
        //
        // Choose a pivot i:
        //   target[0 ... i-1] stays equal
        //   left[i] > target[i]
        //   everything after i is made as small as possible
        //
        // Try pivots from right to left.
        // ------------------------------------------------------------
        for (int i = m - 1; i >= 0; i--) {
            // Check whether target[0 ... i-1] can be used.
            vector<int> cur = halfCnt;
            bool prefixPossible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cur[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                cur[x]--;
            }

            if (!prefixPossible) continue;

            // At position i, choose the smallest available character
            // strictly larger than target[i].
            int t = target[i] - 'a';

            for (int c = t + 1; c < 26; c++) {
                if (cur[c] == 0) continue;

                string left;
                left.reserve(m);

                // Fixed prefix.
                for (int j = 0; j < i; j++) {
                    left.push_back(target[j]);
                }

                // Pivot.
                left.push_back(char('a' + c));

                cur[c]--;

                // Fill remaining positions with smallest characters.
                for (int ch = 0; ch < 26; ch++) {
                    left.append(cur[ch], char('a' + ch));
                }

                return makePalindrome(left);
            }
        }

        return "";
    }
};
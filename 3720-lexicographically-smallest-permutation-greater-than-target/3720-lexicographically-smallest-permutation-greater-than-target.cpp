class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // freq[i] = frequency of remaining characters
        // after matching target[0 ... i-1]
        vector<array<int, 26>> freq(n + 1);

        freq[0].fill(0);

        for (char c : s) {
            freq[0][c - 'a']++;
        }

        int matched = 0;

        // Match target from left to right as much as possible
        for (int i = 0; i < n; i++) {
            freq[i + 1] = freq[i];

            int x = target[i] - 'a';

            if (freq[i + 1][x] == 0) {
                break;
            }

            freq[i + 1][x]--;
            matched++;
        }

        // If target itself can be completely formed,
        // start from the last position because we need
        // the next lexicographically greater permutation.
        //
        // Otherwise, start from the first unmatched position.
        int start = (matched == n ? n - 1 : matched);

        for (int i = start; i >= 0; i--) {
            // freq[i] contains characters remaining after
            // matching target[0 ... i-1]
            auto cnt = freq[i];

            int x = target[i] - 'a';

            // Find the smallest available character
            // strictly greater than target[i].
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);

                // Put the smallest greater character here
                ans += char('a' + c);
                cnt[c]--;

                // Put all remaining characters in sorted order
                for (int j = 0; j < 26; j++) {
                    ans.append(cnt[j], char('a' + j));
                }

                return ans;
            }
        }

        return "";
    }
};
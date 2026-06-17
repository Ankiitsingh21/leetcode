class Solution {
public:
    char processStr(string s, long long k) {
         long long len = 0;

        // First pass: calculate final length
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                len++;
            }
            else if (ch == '*') {
                if (len > 0) {
                    len--;
                }
            }
            else if (ch == '#') {
                if (len > 0) {
                    len *= 2;
                }
            }
            // '%' does not change the length

            // We only care about positions up to k
            // if (len > k + 1) {
            //     len = k + 1;
            // }
        }

        // k is out of bounds
        if (k >= len) {
            return '.';
        }

        // Second pass: go backwards
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                // This character was appended at position len-1
                if (k == len - 1) {
                    return ch;
                }
                len--;
            }
            else if (ch == '*') {
                // Forward: pop_back()
                // Backward: restore one deleted character
                len++;
            }
            else if (ch == '#') {
                // Forward: A -> AA
                if (len > 0) {
                     long long originalLen = (len ) / 2;

                    k %= originalLen;
                    len = originalLen;
                }
            }
            else if (ch == '%') {
                // Forward: reverse
                if (len > 0) {
                    k = len - 1 - k;
                }
            }
        }

        return '.';
    }
};
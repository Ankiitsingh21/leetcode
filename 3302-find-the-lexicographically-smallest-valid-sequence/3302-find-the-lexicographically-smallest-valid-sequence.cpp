class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last[j] stores the largest index in word1 such that word2[j...m-1] 
        // can be matched as a subsequence in word1[last[j]...n-1] without any changes.
        vector<int> last(m, -1);
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            last[j] = ptr;
            if (ptr >= 0) {
                ptr--; // move left for the next character
            }
        }

        vector<int> result;
        bool modified = false;
        int i = 0; // Pointer for word1

        for (int j = 0; j < m; ++j) {
            bool matched = false;

            while (i < n) {
                // Check if current characters match
                if (word1[i] == word2[j]) {
                    result.push_back(i);
                    i++;
                    matched = true;
                    break;
                } 
                // Check if we can apply a modification at word1[i] -> word2[j]
                else if (!modified) {
                    bool can_finish = (j + 1 == m) || (last[j + 1] > i);
                    if (can_finish) {
                        result.push_back(i);
                        modified = true;
                        i++;
                        matched = true;
                        break;
                    }
                }
                
                i++;
            }

            // If we couldn't match word2[j], no valid sequence exists
            if (!matched) {
                return {};
            }
        }

        return result;
    }
};
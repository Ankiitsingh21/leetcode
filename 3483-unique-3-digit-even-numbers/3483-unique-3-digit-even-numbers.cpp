class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {};
        
        // Frequency of each digit
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;

        // Hundreds digit cannot be 0
        for (int a = 1; a <= 9; a++) {
            if (count[a] == 0) continue;

            // Tens digit
            for (int b = 0; b <= 9; b++) {
                if (count[b] == 0) continue;

                // Units digit must be even
                for (int c = 0; c <= 8; c += 2) {
                    if (count[c] == 0) continue;

                    // Use a, b, c
                    count[a]--;
                    count[b]--;
                    count[c]--;

                    // Check whether all three copies are available
                    if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0) {
                        ans++;
                    }

                    // Restore
                    count[a]++;
                    count[b]++;
                    count[c]++;
                }
            }
        }

        return ans;
    }
};
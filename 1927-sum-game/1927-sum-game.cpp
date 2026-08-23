class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int qDiff = 0;

        for (int i = 0; i < n; i++) {
            int sign = (i < half ? 1 : -1);

            if (num[i] == '?') {
                qDiff += sign;
            } else {
                diff += sign * (num[i] - '0');
            }
        }

        // Bob wins only if the difference can be
        // exactly cancelled by the question marks.
        return 2 * diff + 9 * qDiff != 0;
    }
};
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Impossible if the digit sum is too large.
        if (sum > 9 * num)
            return "";

        string ans;

        // Put as much sum as possible into 9s.
        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        // Put the remaining sum into one digit.
        if (sum > 0) {
            ans += char('0' + sum);
        }

        // Fill remaining positions with 0.
        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};
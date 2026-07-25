class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int secondMaxi = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit >= maxi) {
                secondMaxi = maxi;
                maxi = digit;
            } else if (digit > secondMaxi) {
                secondMaxi = digit;
            }
            n /= 10;
        }
        return maxi * secondMaxi;
    }
};
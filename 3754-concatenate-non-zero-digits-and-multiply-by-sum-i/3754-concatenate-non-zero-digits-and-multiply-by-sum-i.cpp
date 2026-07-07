class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp=n;
        long long sum = 0;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }

        int cnt = 1;
        int x = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                x += digit * cnt;
                cnt *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};
class Solution {
    long long MOD = 1e9 + 7;

    long long myPow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            n /= 2;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long res =
            (myPow(5, evenPositions) * myPow(4, oddPositions)) % MOD;
        return (int)res;
    }
};
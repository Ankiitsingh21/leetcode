class Solution {
    long long myPow(long long x, long long N) {
        long long n = N;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % 1337;
                n--;
            } else {
                x = (x * x) % 1337;
                n = n / 2;
            }
        }
        return ans;
    }

public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;

        for (int digit : b) {
            ans = myPow(ans, 10) % 1337;
            ans = (ans * myPow(a, digit)) % 1337;
        }

        return ans;
    }
};
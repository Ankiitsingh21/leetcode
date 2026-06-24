class Solution {
public:
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &a, Matrix &b) {
        int n = a.size();

        Matrix ans(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    ans[i][j] = (ans[i][j] + 
                                a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return ans;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        // identity matrix
        for (int i = 0; i < n; i++)
            res[i][i] = 1;


        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }


    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;      // max 75
        int states = 2 * m;

        /*
           index:
           value i UP   -> i
           value i DOWN -> i + m
        */

        vector<long long> start(states, 0);


        // build arrays of length 2
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a == b) continue;

                if (b > a)
                    start[b]++;       // UP
                else
                    start[b + m]++;   // DOWN
            }
        }


        Matrix trans(states, vector<long long>(states, 0));


        // create transition matrix
        for (int old = 0; old < m; old++) {

            // old state UP
            int oldUP = old;

            // next must be smaller -> DOWN
            for (int nxt = 0; nxt < old; nxt++) {
                trans[nxt + m][oldUP] = 1;
            }


            // old state DOWN
            int oldDOWN = old + m;

            // next must be greater -> UP
            for (int nxt = old + 1; nxt < m; nxt++) {
                trans[nxt][oldDOWN] = 1;
            }
        }


        Matrix mat = power(trans, n - 2);


        vector<long long> finalState(states, 0);

        for (int i = 0; i < states; i++) {
            for (int j = 0; j < states; j++) {
                finalState[i] = (finalState[i] +
                    mat[i][j] * start[j]) % MOD;
            }
        }


        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        // up[i][j]   = arrays ending at value j with last move increasing
        // down[i][j] = arrays ending at value j with last move decreasing

        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));


        // length 2 initialization
        for(int prev=0; prev<m; prev++){
            for(int curr=0; curr<m; curr++){

                if(prev == curr) continue;

                if(prev < curr)
                    up[1][curr]++;
                else
                    down[1][curr]++;
            }
        }


        for(int len=2; len<n; len++){

            vector<int> prefUp(m+1,0);
            vector<int> prefDown(m+1,0);

            for(int i=0;i<m;i++){
                prefUp[i+1] = (prefUp[i] + up[len-1][i]) % MOD;
                prefDown[i+1] = (prefDown[i] + down[len-1][i]) % MOD;
            }


            for(int curr=0; curr<m; curr++){

                // previous move was decreasing,
                // now we need increasing
                // previous value < curr
                up[len][curr] = prefDown[curr];


                // previous move was increasing,
                // now we need decreasing
                // previous value > curr
                down[len][curr] =
                    (prefUp[m] - prefUp[curr+1] + MOD) % MOD;
            }
        }


        long long ans = 0;

        for(int i=0;i<m;i++){
            ans = (ans + up[n-1][i]) % MOD;
            ans = (ans + down[n-1][i]) % MOD;
        }

        return ans;
    }
};
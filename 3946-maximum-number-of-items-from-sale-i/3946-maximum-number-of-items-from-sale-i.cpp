
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Calculate the value of each item type.
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0) {
                    freeItems++;
                }
            }

            val[i] = 1 + freeItems;
        }

        // Group items by their price.
        vector<vector<int>> groups(1501);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            groups[price].push_back(val[i]);
        }

        const int NEG = -1e9;

        // dp[c]: Best value using items with price > current price.
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Step 2: Process prices in descending order.
        for (int p = 1500; p >= 1; p--) {

            if (groups[p].empty()) continue;

            // one[c]: Best value with at least one item
            // from the current price group.
            vector<int> one(budget + 1, NEG);

            // Step 3: Select at least one item of price p.
            for (int v : groups[p]) {
                for (int c = budget; c >= p; c--) {

                    if (dp[c - p] != NEG) {
                        one[c] = max(
                            one[c],
                            dp[c - p] + v
                        );
                    }

                    if (one[c - p] != NEG) {
                        one[c] = max(
                            one[c],
                            one[c - p] + v
                        );
                    }
                }
            }

            // Step 4: Calculate maximum total items.
            for (int c = p; c <= budget; c++) {
                if (one[c] == NEG) continue;

                int extra = (budget - c) / p;

                ans = max(ans, one[c] + extra);
            }

            // Step 5: Add current price group to normal DP.
            for (int v : groups[p]) {
                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        dp[c] = max(dp[c],
                                    dp[c - p] + v);
                    }
                }
            }
        }

        return ans;
    }
};

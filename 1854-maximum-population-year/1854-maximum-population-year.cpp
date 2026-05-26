class Solution {
    void changee(vector<int>& arr, int l, int r, int n, int change) {
        arr[l] += change;
        if (r + 1 < n) {
            arr[r + 1] -= change;
        }
    }
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       int base = 1950;
        int n = 101; // 2050 - 1950 + 1

        vector<int> diff(n, 0);

        for (int i = 0; i < logs.size(); i++) {
            int l = logs[i][0] - base;        // birth
            int r = logs[i][1] - 1 - base;    // death - 1 (inclusive range)
            changee(diff, l, r, n, 1);
        }

        int curr = 0, maxPop = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            curr += diff[i];
            if (curr > maxPop) {
                maxPop = curr;
                ans = i;
            }
        }

        return ans + base;
    }
};
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Bitmask for each row:
        // bit 0 -> seat 2
        // bit 1 -> seat 3
        // ...
        // bit 7 -> seat 9
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if (s >= 2 && s <= 9) {
                rows[row] |= (1 << (s - 2));
            }
        }

        // Every completely empty row can have 2 groups.
        long long ans = 2LL * (n - rows.size());

        for (auto &[row, mask] : rows) {
            // Left block: 2,3,4,5
            bool left = (mask & 0b00001111) == 0;

            // Middle block: 4,5,6,7
            bool middle = (mask & 0b00111100) == 0;

            // Right block: 6,7,8,9
            bool right = (mask & 0b11110000) == 0;

            if (left && right) {
                ans += 2;
            } 
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return (int)ans;
    }
};
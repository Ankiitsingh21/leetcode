class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();

        int ans = 0;
        int cover = 0;

        int j = 0;

        for (int i = 0; i < n; i++) {

            // add full tiles while carpet can cover them
            while (j < n && tiles[j][1] < tiles[i][0] + carpetLen) {
                cover += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }

            int extra = 0;

            // partially covered tile
            if (j < n) {
                extra = max(0, 
                    tiles[i][0] + carpetLen - tiles[j][0]
                );
            }

            ans = max(ans, cover + extra);


            // remove left tile when moving carpet start
            cover -= tiles[i][1] - tiles[i][0] + 1;
        }

        return ans;
    }
};
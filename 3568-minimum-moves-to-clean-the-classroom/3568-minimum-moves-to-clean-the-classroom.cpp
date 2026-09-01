class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell a bit number.
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;
        int sr = -1, sc = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // best[mask][cell] = maximum energy seen
        // when we reach this cell with this mask.
        vector<vector<int>> best(
            1 << litterCount,
            vector<int>(m * n, -1)
        );

        struct State {
            int r, c;
            int mask;
            int energy;
        };

        queue<State> q;

        int startCell = sr * n + sc;

        best[0][startCell] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            // Process one BFS level = same number of moves.
            while (sz--) {
                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                if (mask == fullMask) {
                    return moves;
                }

                // If energy is 0, we cannot make another move
                // unless we are standing on a reset cell.
                if (currEnergy == 0 && classroom[r][c] != 'R') {
                    continue;
                }

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = currEnergy - 1;

                    // We can only move if we have energy.
                    if (newEnergy < 0)
                        continue;

                    int newMask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        newMask |= (1 << id);
                    }

                    // Reset energy after entering R.
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int cell = nr * n + nc;

                    // Dominance check:
                    // If we've already reached this exact
                    // (cell, mask) with >= energy, this state
                    // can never be better.
                    if (best[newMask][cell] >= newEnergy)
                        continue;

                    best[newMask][cell] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};
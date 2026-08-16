class Solution {
public:
    bool check(int zero, int one, int two) {
        // Alice starts by taking a remainder-1 stone.
        if (one == 0)
            return false;

        one--;

        // Then the game is forced to alternate:
        // 1 -> 2 -> 1 -> 2 -> ...
        int len = 1 + min(one, two) * 2 + zero;

        // If there are extra 1's, one more 1 can be taken.
        if (one > two) {
            one--;
            len++;
        }

        // Alice wins if:
        // 1. The number of moves is odd, so Bob is forced to make
        //    the losing move.
        // 2. There are still non-zero-remainder stones left;
        //    otherwise all stones are consumed and Bob wins automatically.
        return (len % 2 == 1) && (one != two);
    }

    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // Try Alice starting with remainder 1
        if (check(cnt[0], cnt[1], cnt[2]))
            return true;

        // Try Alice starting with remainder 2
        if (check(cnt[0], cnt[2], cnt[1]))
            return true;

        return false;
    }
};
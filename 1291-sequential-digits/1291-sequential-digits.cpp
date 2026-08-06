class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        deque<int> q;
        for (int i = 1; i < 10; i++) {
            q.push_back(i);
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop_front();
            if (n > high)
                continue;

            if (n >= low && n <= high) {
                ans.push_back(n);
            }
            int ones = n % 10;
            if (ones < 9) {
                q.push_back(n * 10 + (ones + 1));
            }
        }
        return ans;
    }
};
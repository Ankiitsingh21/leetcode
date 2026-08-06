class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string a = to_string(low);
        string b = to_string(high);
        int l = a.size();
        int h = b.size();
        for (int i = l; i < h + 1; i++) {
            for (int j = 1; j < 9; j++) {
                if (i + j > 10)
                    break;
                int num = j;
                int prev = j;
                for (int k = 0; k < i - 1; k++) {
                    num *= 10;
                    prev++;
                    num += prev;
                }

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};
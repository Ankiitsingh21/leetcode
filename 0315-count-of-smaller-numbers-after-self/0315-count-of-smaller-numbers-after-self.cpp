class Solution {
    void update(vector<int>& bits, int val, int id, int n) {
        while (id <= n) {
            bits[id] += val;
            id += (id & -id);
        }
        return;
    }
    int query(vector<int>& bits, int id) {
        int sum = 0;
        while (id > 0) {
            sum += bits[id];
            id &= (id - 1);
        }
        return sum;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(n + 1, 0);
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(n, 0);
        for (auto& [val, id] : arr) {
            update(bits, 1, id + 1, n);
            ans[id] = query(bits, n) - query(bits, id + 1);
        }
        return ans;
    }
};
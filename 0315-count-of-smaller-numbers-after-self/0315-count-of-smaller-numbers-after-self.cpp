class Solution {
    void update(vector<int>& bits, int id, int n) {
        while (id <= n) {
            bits[id] += 1;
            id += (id & -id);
        }
        return;
    }
    int query(vector<int>& bits, int id) {
        int sum = 0;
        while (id > 0) {
            sum += bits[id];
            id -= (id & -id);
        }
        return sum;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(nums.size(), 0);
        vector<int> bits(nums.size() + 1, 0);
        for (auto& [el, id] : arr) {
            update(bits, id + 1, nums.size());
            ans[id] = query(bits, nums.size()) - query(bits, id + 1);
        }
        return ans;
    }
};
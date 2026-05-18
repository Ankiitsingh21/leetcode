class Solution {
    vector<pair<int,int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; i++) {
            if (ans.empty() || nums[i][0] > ans.back().second) {
                ans.push_back({nums[i][0],nums[i][1]});
            } else {
                ans.back().second = max(ans.back().second, nums[i][1]);
            }
        }
        return ans;
    }

public:
    int countDays(int days, vector<vector<int>>& arr) {
        // vector<pair<int,int>> nums = merge(arr);
        sort(arr.begin(),arr.end());
        int prev_end=0;
        for (auto& v: arr) {
            int start=max(v[0],prev_end+1);
            int length = v[1] - start + 1;
            days -= max(length, 0);
            prev_end=max(v[1],prev_end);
        }
        return days;
    }
};
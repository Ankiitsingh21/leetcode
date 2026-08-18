class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> count(51, 0);

        for (int i = 0; i + k <= nums.size(); i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                count[x]++;
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};
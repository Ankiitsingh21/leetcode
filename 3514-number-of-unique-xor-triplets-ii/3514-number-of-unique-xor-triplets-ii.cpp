class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 1 || n == 2)
        //     return n;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                // for(int k=j;k<nums.size();k++){
                st.insert(nums[i] ^ nums[j]);
                // }
            }
        }

        unordered_set<int> ans;
        for (int x : st) {
            for (int s : nums) {
                ans.insert(x ^ s);
            }
        }
        return ans.size();
    }
};
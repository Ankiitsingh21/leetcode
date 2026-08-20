class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        vector<int> ans;
        for (int& num : nums) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(num);
            } else {
                arr2.push_back(num);
            }
        }
        for (int& num : arr1) {
            ans.push_back(num);
        }
        for (int& num : arr2) {
            ans.push_back(num);
        }
        return ans;
    }
};
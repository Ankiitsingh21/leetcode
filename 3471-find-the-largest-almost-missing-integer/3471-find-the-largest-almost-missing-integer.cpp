class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()){
            int maxi=INT_MIN;
            for(int &x:nums){
                maxi=max(maxi,x);
            }
            return maxi;
        }
        vector<int> count(51, 0);

        for (int i = 0; i + k <= nums.size(); i++) {
            for (int j = i; j < i + k; j++) {
                count[nums[j]]++;
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
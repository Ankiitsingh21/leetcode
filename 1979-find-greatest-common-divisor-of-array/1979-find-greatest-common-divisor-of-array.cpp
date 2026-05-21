class Solution {
    int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        return gcd(maxi,mini);
    }
};
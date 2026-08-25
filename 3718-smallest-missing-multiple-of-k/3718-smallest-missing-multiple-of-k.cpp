class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int& num : nums) {
            mpp[num]++;
        }
        for (int i = 1; i < 102; i++) {
            // cout<<k<<" "<<endl;
            if (mpp.find(k * i) == mpp.end())
                return k * i;
            // k*=k;
        }
        return 0;
    }
};
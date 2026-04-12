class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        // Loop through each index
        for (int i = 0; i < n; i++) {
            // If the current index is beyond our maximum reach, it's impossible.
            if (i > maxi) {
                return false;
            }
            // Update the maximum reach
            maxi = max(maxi, i + nums[i]);
            
            // Optimization: If our reach already covers the end, we can stop early.
            // if (maxi >= n - 1) {
            //     return true;
            // }
        }
        
        // This line is technically unreachable if n > 0 because of the check inside the loop,
        // but it ensures a return path. For an empty or single-element array, the initial
        // state or the first loop iteration will handle it.
        return true; 
    }
};
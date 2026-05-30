class Solution {
    int solve(int index, vector<int>& arr, int sign) {
        if (index == arr.size())
            return 0;

        if (sign == 0) {
            int diff = arr[index] - arr[index - 1];
            if (diff == 0)
                return 0;
            if (diff < 0) {
                return 1 + solve(index + 1, arr, 1);
            } else {
                return 1 + solve(index + 1, arr, -1);
            }
        } else if (sign == 1 && arr[index] > arr[index - 1]) {
            return 1 + solve(index + 1, arr, -1);
        } else if (sign == -1 && arr[index] < arr[index - 1]) {
            return 1 + solve(index + 1, arr, 1);
        }
        return 0;
    }

public:
    int maxTurbulenceSize(vector<int>& arr) {
        // if(arr.size()==1) return 1;
        // int ans = 1;
        // for (int i = 0; i < arr.size()-1; i++) {
        //     // cout<<arr[i]<<" "<<i<<" "<<endl;
        //     ans = max(ans,  1+slideSolve(i + 1, arr, 0));
        // }
        // return ans;

        int l = 0, r = 1;
        int ans = 1;
        while (r < arr.size()) {

            long long curr = arr[r] - arr[r - 1];
            if (curr == 0) {
                l = r;
            } else if (r == arr.size() - 1 ||
                       curr * (arr[r+1] - arr[r]) >= 0) {
                ans = max(ans, r - l + 1);
                l = r;
            }
            r++;
        }
        return ans;
    }
};
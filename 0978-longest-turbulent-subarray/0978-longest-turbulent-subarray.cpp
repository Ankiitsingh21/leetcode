class Solution {
    int solve(int index, vector<int>& arr, int sign) {
        if (index == arr.size())
            return 0;

        if (sign == 0) {
            int diff = arr[index] - arr[index - 1];
            if(diff==0) return 0;
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
        if(arr.size()==1) return 1;
        int ans = 1;
        for (int i = 0; i < arr.size()-1; i++) {
            // cout<<arr[i]<<" "<<i<<" "<<endl;
            ans = max(ans,  1+solve(i + 1, arr, 0));
        }
        return ans;
    }
};
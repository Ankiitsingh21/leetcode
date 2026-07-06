class Solution {
    int high(vector<int>& arr, int x) {
        if (arr[0] >= x)
            return 0;
        if (arr.back() < x)
            return arr.size();
        int low = 0, high = arr.size() - 1;
        int mid = low + (high - low) / 2;

        // cout<<"hi"<<" ";
        while (low < high) {
            mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = high(arr, x);
        // cout<<start<<" ";
        vector<int> ans;
        if (start == 0) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }
        if (start == arr.size() ) {
            int l = arr.size() - k;
            for (; l < arr.size(); l++) {
                ans.push_back(arr[l]);
            }
            return ans;
        }
        // int val = a;
        int l = start - 1;
        int r = start;
        while (l >= 0 && r < arr.size()) {
            int a = arr[l];
            int b = arr[r];
            int diff1 = abs(x - a);
            int diff2 = abs(x - b);
            // cout<<a<<" "<<b<<" "<<diff1<<" "<<diff2<<" "<<endl;
            if (diff1 == diff2) {
                ans.push_back(a);
                l--;
            } else if (diff1 < diff2) {
                ans.push_back(a);
                l--;
            } else {
                ans.push_back(b);
                r++;
            }

            if (ans.size() == k)
                break;
        }
        while (ans.size() != k && l >= 0) {
            ans.push_back(arr[l]);
            l--;
        }
        while (ans.size() != k && r < arr.size()) {
            ans.push_back(arr[r]);
            r++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
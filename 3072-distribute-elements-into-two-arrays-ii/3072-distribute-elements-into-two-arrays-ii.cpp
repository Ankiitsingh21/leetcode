class Solution {
    void update(int id, int n, vector<int>& bits) {
        while (id <= n) {
            bits[id] += 1;
            id += id & (-id);
        }
        return;
    }
    int query(int id, vector<int>& bits) {
        int sum = 0;
        while (id > 0) {
            sum += bits[id];
            id -= id & (-id);
        }
        return sum;
    }

public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        int m = comp.size();
        vector<int> bits1(m + 1), bits2(m + 1);
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int lw1 =
            lower_bound(comp.begin(), comp.end(), nums[0]) - comp.begin() + 1;
        int lw2 =
            lower_bound(comp.begin(), comp.end(), nums[1]) - comp.begin() + 1;
        update(lw1, m, bits1);
        update(lw2, m, bits2);

        for (int i = 2; i < n; i++) {
            int idx = lower_bound(comp.begin(), comp.end(), nums[i]) -
                      comp.begin() + 1;

            int greater1 = arr1.size() - query(idx, bits1);
            int greater2 = arr2.size() - query(idx, bits2);

            if (greater1 > greater2) {
                arr1.push_back(nums[i]);
                update(idx, m, bits1);
            } else if (greater1 < greater2) {
                arr2.push_back(nums[i]);
                update(idx, m, bits2);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    update(idx, m, bits1);
                } else {
                    arr2.push_back(nums[i]);
                    update(idx, m, bits2);
                }
            }
        }
        vector<int> ans;
        ans.insert(ans.end(), arr1.begin(), arr1.end());
        ans.insert(ans.end(), arr2.begin(), arr2.end());
        return ans;
    }
};
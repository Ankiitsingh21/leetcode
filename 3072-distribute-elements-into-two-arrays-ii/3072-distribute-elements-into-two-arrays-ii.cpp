#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
class Solution {
    typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
                 tree_order_statistics_node_update>
        ordered_set;

public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans, arr1, arr2;
        ordered_set st1, st2;
        st1.insert({nums[0], 0});
        st2.insert({nums[1], 0});

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        //    nums.erase(nums.begin());
        //    nums.erase(nums.begin());
        for (int i = 2; i < nums.size(); i++) {
            int val = nums[i] + 1;
            int id1 = st1.order_of_key({val, 0});
            int id2 = st2.order_of_key({val, 0});
            int sz1 = arr1.size() - id1;
            int sz2 = arr2.size() - id2;

            if (sz1 > sz2) {
                arr1.push_back(val - 1);
                st1.insert({val - 1, i});
            } else if (sz1 < sz2) {
                arr2.push_back(val - 1);
                st2.insert({val - 1, i});
            } else {
                if (arr1.size() > arr2.size()) {
                    arr2.push_back(val - 1);
                    st2.insert({val - 1, i});
                } else {
                    arr1.push_back(val - 1);
                    st1.insert({val - 1, i});
                }
            }
        }
        for(int &num:arr1){
            ans.push_back(num);
        }
        for(int &num:arr2){
            ans.push_back(num);
        }
        return ans;
    }
};
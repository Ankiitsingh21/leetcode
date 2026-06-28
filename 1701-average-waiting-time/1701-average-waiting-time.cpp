class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // sort(customers.begin(), customers.end());
        // for(int i=0;i<customers.size();i++){
        //     cout<<customers[i][0]<<" "<<customers[i][1]<<" "<<endl;
        // }
        double totalWt = 0;
        int time = customers[0][0];
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i][0] > time) {
                time += (customers[i][0] - time);
            }
             time += customers[i][1];
            totalWt += (time - customers[i][0]);
            // cout<<totalWt<<" "<<wait<<" "<<customers[i][0]<<" "<<i<<" "<<endl;
            // time += customers[i][1];
        }
        cout<<totalWt<<" ";
        return totalWt / customers.size();
    }
};
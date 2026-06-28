class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWt = 0;
        int time = customers[0][0];
        for (int i = 0; i < customers.size(); i++) {
            time = max(time, customers[i][0]);
            time += customers[i][1];
            totalWt += (time - customers[i][0]);
        }
        return totalWt / customers.size();
    }
};
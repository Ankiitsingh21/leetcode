class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gsum=0;
        int csum=0;
        for(int i=0;i<gas.size();i++){
            gsum+=gas[i];
            csum+=cost[i];
        }
        if(gsum<csum) return -1;
        int start=0;
        int curr=0;
        for(int i=0;i<gas.size();i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        return start;
    }
};
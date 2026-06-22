class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startindex=0, currenttank=0, totalsurplus=0;
        for(int i=0;i<gas.size();i++){
            int diff = gas[i]-cost[i];
            totalsurplus+=diff;
            currenttank+=diff;
            if(currenttank<0){
                startindex=i+1;
                currenttank=0;
            }
        }
        return totalsurplus>=0 ? startindex:-1;
    }
};

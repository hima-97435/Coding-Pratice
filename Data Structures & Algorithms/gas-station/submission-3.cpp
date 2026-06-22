class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start=n-1, end=0;
        int diff = gas[start]-cost[start];
        while(start>end){
            if(diff<0){
                start--;
                diff+=gas[start]- cost[start];
            }
            else{
                diff+=gas[end]-cost[end];
                end++;

            }
        }
        cout<<diff<<endl;
        return diff>=0 ? start:-1;
    }
};

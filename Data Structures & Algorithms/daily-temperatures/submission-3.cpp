class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-2;i>=0;i--){
          for(int j=i+1;j<n;j++){
            if(temperatures[i]<temperatures[j]){
              ans[i]=(j-i);
              break;
            }
          }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> ans(temperatures.size(),0);
      for( int i=0;i<temperatures.size();i++){
            for( int j=i+1;j<temperatures.size();j++){
                cout<<temperatures[j]<< " ";
                if(temperatures[j] > temperatures[i]) {
                    ans[i]=j-i;
                    break;
                }
            }
      }  
      return ans;
    }
};

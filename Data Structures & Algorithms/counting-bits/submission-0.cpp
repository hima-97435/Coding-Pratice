class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for ( int i=0;i<=n ;i++){
            int res =0;
            int j =i;
            while(j>0){
                j= j&(j-1);
                res++;
            }
            ans.push_back(res);
        } 
        return ans;
    }
};

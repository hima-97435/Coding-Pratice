class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        int i=0;
        for( int x: nums){
        
            res^=i^x;
            
            i++;
            cout<<"res: "<<res<<" "<<"i: "<<i<<endl;
        }
        cout<<endl;
        return res;
    }
};

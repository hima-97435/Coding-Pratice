class Solution {
public:
    int func(vector<int>& nums, int i, int n){
        /* Debugging
        cout<<i<<" "<<n<<endl;
        for( int x: nums) cout<<x<<" ";
        cout<<endl;
        */
        if( i == n) return nums[i];
        int oneback = max(nums[i], nums[i+1]);
        int twoback = nums[i];
        // cout<<oneback<<" "<<twoback<<endl;
        for( int x = i+2;x<=n;x++){
            // cout<<"nums[i] : "<<nums[x]<<endl;
            int emp = max(nums[x]+twoback, oneback);
            twoback= oneback;
            oneback= emp;
            // cout<< "emp : "<<emp<<" twoback : "<<twoback<<" Oneback :"<<oneback<<endl;
        }
        return oneback;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        cout<<"first : "<<endl;
        if( n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(func(nums,0, n-2),func(nums, 1 , n-1));
        
    }
};

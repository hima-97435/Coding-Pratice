class Solution {
public:
    string gkey(vector<int> nums){
        string tmp="";
        for(int i=0;i<nums.size();i++){
            tmp+=to_string(nums[i])+",";
        }
        tmp.pop_back();
        
        return tmp;
    }
    int maxCoins(vector<int>& nums) {
        unordered_map<string, int> cache;
        auto dfs = [&](auto &&self,vector<int>&nums)->int{
            if(nums.empty()) return 0;
            string k = gkey(nums);
            if(cache.count(k)) return cache[k];
            int ans =0;
            for(int i=0;i<nums.size();i++){
                int l = (i ==0)?1:nums[i-1];
                int r = (i == nums.size()-1)?1:nums[i+1];
                int coins= l*nums[i]*r;
                int val = nums[i];
                nums.erase(nums.begin()+i);
                int remain = self(self,nums);
                nums.insert(nums.begin()+i,val);
                ans=max(ans,remain+coins);
            } 
            cache[k]=ans;
            return ans;
        };
        // cout<<gkey(nums)<<endl;
        return dfs(dfs,nums);

    }
};



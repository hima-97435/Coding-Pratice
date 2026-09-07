class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        string upto(n,'0');
        auto rec = [&](auto &&self, string upto)-> void{
            if(temp.size() == nums.size()) {
                ans.push_back(temp);
                return;
            }
            unordered_set<int> usedatthislevel;
            for(int i=0;i<n;i++){
                if(upto[i] == '1') continue;
                if(usedatthislevel.count(nums[i])) continue;
                usedatthislevel.insert(nums[i]);
                temp.push_back(nums[i]);
                upto[i] = '1';
                self(self,upto);
                
                upto[i]='0';
                temp.pop_back();
            }
        };
        rec(rec,upto);
        return ans;
    }
};
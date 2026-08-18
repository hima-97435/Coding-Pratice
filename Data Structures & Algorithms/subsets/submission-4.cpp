class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        auto backtrack= [&](auto &&self, int i )->void{
            if(i == nums.size()){
                ans.push_back(temp);
                return;
            }
            temp.push_back(nums[i]);
            self(self,i+1);
            temp.pop_back();
            self(self,i+1);
        };    
        backtrack(backtrack,0);
        return ans;
    }
    

};

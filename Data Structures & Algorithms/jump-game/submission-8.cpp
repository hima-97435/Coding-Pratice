class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> cache;
        auto dfs = [&](auto&&self, int i)->bool{
            if(cache.count(i)) return cache[i];
            if(i == nums.size()-1) return true;
            if(nums[i] == 0) return false;
            int end = min((int)nums.size()-1, i+nums[i]);
            for(int j=i+1;j<=end;j++) {
                if(self(self,j)) return cache[j]=true;
            }
            return cache[i]=false;
        };
        return dfs(dfs,0);
    }

};

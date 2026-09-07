class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans =0;
        auto recrusrion = [&] (auto&&self, int index, int currentxor) -> int{
            if(index == nums.size()) return currentxor;
            int take = self(self,index+1, currentxor^nums[index]);
            int skip = self(self,index+1,currentxor);
            return take+skip;
        };
        return recrusrion(recrusrion,0,0);
    }
};
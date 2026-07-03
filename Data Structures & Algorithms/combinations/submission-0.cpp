class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        backtrack(1,n,k,combination);
        return res;
    }
    void backtrack(int i , int n , int k , vector<int> & combination){
        if(i>n) {
            if(combination.size() == k) res.push_back(combination);
            return;
        }
        combination.push_back(i);
        backtrack(i+1,n , k, combination);
        combination.pop_back();
        backtrack(i+1,n,k,combination);
    }
};
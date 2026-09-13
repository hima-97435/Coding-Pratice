class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        vector<vector<int>> cache(m , vector<int>(n,-1));
        auto dfs = [&] (auto &&self, int i , int j )-> int{
            if(i == m ) return n-j;
            if(j == n ) return m-i;
            if(cache[i][j] != -1) return cache[i][j];
            if(word1[i] == word2[j]) return self(self,i+1,j+1);
            return cache[i][j] = min({self(self,i,j+1),self(self,i+1,j), self(self,i+1,j+1)}) +1;
            
        };
        return dfs(dfs,0,0);
        
    }
};

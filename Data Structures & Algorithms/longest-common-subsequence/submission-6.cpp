class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        if(m<n) return longestCommonSubsequence(text2,text1);
        // vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=1;i<=m;i++){
            int diagonal =0;

            for( int j =1;j<=n;j++){
                int temp=curr[j];

                if(text1[i-1] == text2[j-1] ){
                    curr[j]=1+diagonal;
                }
                else {
                    curr[j]=max(curr[j],curr[j-1]);
                }
                diagonal=temp;
            }
            // prev=curr;
        }

        return curr[n];
    }
};

class Solution {
public:
    int numDecodings(string s) {
    //    int dp =0, dp2=0;
    //    int dp1 =1;
    //    int n = s.size();
    //    for( int i=n-1;i>=0;i--){
    //     if(s[i]=='0'){
    //         dp=0;

    //     }
    //     else {
    //         dp = dp1;
    //         if(i+1<s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <'7')){
    //             dp+=dp2;

    //         }
    //     }
    //     dp2=dp1;
    //     dp1=dp;
    //     dp=0;
    //    } 
    //    return dp1;
    // }
    int n = s.size();
    vector<int> vec(n+1);
    vec[n]=1;
    for( int i=n-1;i>=0;i--){
        if(s[i] == '0') vec[i]=0;
        else {
            vec[i]=vec[i+1];
            if(i+1<n && ( s[i] =='1' || s[i] =='2' && s[i+1]<'7' )) {
                vec[i]+=vec[i+2];
            }
        }
        
    }
    return vec[0];
    }
};

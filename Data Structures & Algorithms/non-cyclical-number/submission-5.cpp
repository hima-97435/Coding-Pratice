class Solution {
public:
    int multiplenumbers(int n ){
        int ans = 0;
        while(n!= 0){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
       unordered_set<int> st;
       while(st.find(n) == st.end()){
            st.insert(n);
            n = multiplenumbers(n);
            if(n == 1) return true;
       } 
       return false;
    }
};

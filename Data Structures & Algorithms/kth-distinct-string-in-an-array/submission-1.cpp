class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            bool flag= true;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(arr[i] == arr[j]) {flag= false; break;}
            }
            if(flag){
                k--;
                if( k == 0) return arr[i];
            }
        }
        return "";
    }
};
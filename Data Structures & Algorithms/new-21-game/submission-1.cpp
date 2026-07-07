class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1.0;
        double window_sum =0;
        for(int i=k;i<k+maxPts;i++) window_sum+=(i<=n)?1.0:0.0;
        unordered_map<int, double> mp;
        for(int i=k-1;i>=0;i--){
            mp[i]=window_sum/maxPts;
            double remove = 0.0;
            if(i+maxPts<=n) remove = (mp.find(i+maxPts) != mp.end()) ? mp[i+maxPts]:1.0;
            window_sum+=mp[i]-remove;
        }
     return mp[0];
    }
   
};
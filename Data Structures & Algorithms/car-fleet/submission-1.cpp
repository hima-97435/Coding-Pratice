class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // okay we could do in this way right, given postions which will come start from where
        // we could analyse one thing that certain car satrt when 
        // so to better understand the postion flow we will sort based on postion
        // and based on that we calcaute time 
        // and based on time if certain object take lesser time then further one it will flow as car fleet
        // vector<int> arr = position;
        vector<pair<int , int>> arr;
        
        for(int i=0;i<position.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.rbegin(),arr.rend());
        vector<double> dis(arr.size());
        for( int i=0;i<arr.size();i++){
            dis[i] = (double)(target-arr[i].first)/arr[i].second;
        }
        // arr= { {0,1}, {1,2}, {4,2} ,{7,1} }
        // dis= [ 10,4.5,3,3]

        // dis = [ 4,4,4,4] = o/p =1
        // dis = [4,4,3,3] =2
        // dis = [4,5,6] = 1
        double prev = dis[0];
        int cnt =1;
        for( int i=1;i<dis.size();i++){
            if(dis[i] > prev) {
                cnt++;
                prev=dis[i];
            }
        }
        return cnt;

    }
};

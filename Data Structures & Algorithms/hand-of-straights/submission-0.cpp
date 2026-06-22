class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        map<int , int> mp;
        for( int x: hand){
            mp[x]++;
        }
        while(!mp.empty()){
            int first = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int current = first+i;
                if(mp[current] == 0) return false;
                mp[current]--;
                if(mp[current] == 0) mp.erase(current);
            }
        }
        return true;
    }
};

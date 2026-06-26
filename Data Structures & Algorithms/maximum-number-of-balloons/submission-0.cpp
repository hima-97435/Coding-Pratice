class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        int mini = text.size();
        for(char c: text){
            mp[c]++;
            
        }
        unordered_map<char, int> ballons = {{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
        for(auto &e: ballons){
            mini=min(mini,mp[e.first]/e.second);
        }
        
        return mini;
    }
};
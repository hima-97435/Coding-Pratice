class Twitter {
public:
    vector<pair<int , int>> timeline;
    unordered_map<int , unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for( int i=timeline.size()-1;i>=0;i--){
            if(feed.size() == 10) break;
            int userid = timeline[i].first;
            int tweetid = timeline[i].second;
            if(userid==userId || following[userId].count(userid)) {
                feed.push_back(tweetid);
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }
    }
};

class Twitter {
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        ++order_;
        content_[userId].push_front({order_, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        map<int, list<content>::iterator> buffer{};
        buffer[userId] = content_[userId].begin();
        for (auto followeeId : to_[userId]) {
            buffer[followeeId] = content_[followeeId].begin();
        }

        vector<int> ans{};
        ans.reserve(10);
        for (int i = 0; i < 10; ++i) {
            int maxOrder = 0;
            int userId = 0;
            for (auto& it : buffer) {
                if (it.second != content_[it.first].end()) {
                    if (it.second->order > maxOrder) {
                        userId = it.first;
                        maxOrder = it.second->order;
                    }
                }
            }
            if (userId == 0) {
                return ans;
            }
            ans.push_back(buffer[userId]->tweetId);
            ++buffer[userId];
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        to_[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = to_.find(followerId);
        if (it == to_.end()) {
            return;
        }

        it->second.erase(followeeId);
    }

private:
    map<int, set<int>> to_;

    struct content {
        int order;
        int tweetId;
    };
    map<int, list<content>> content_;

    int order_{0};
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
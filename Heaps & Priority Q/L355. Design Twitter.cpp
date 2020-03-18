/*
 * Author : Shruti Katyal
 * Date   : 07 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * Real Life Problem
 */
class Twitter {
    int timestamp;
    
    class Tweet{
        
        public:
            int id;
            int time;
            Tweet* next;

            Tweet(int id,int timestamp){
                this->id = id;
                this->time = timestamp;
                this->next = NULL;
            }
    };
    
    class User{
        
        public:
            int id;
            unordered_set<int> followed;
            Tweet* headTweet;

            User(int userId){
                id = userId;
                follow(id);
                headTweet = NULL;
            }
        
            void follow(int id){
                followed.insert(id);
            }
        
            void unfollow(int id){
                followed.erase(id);
            }
        
            void post(int id,int timestamp){
                Tweet* t = headTweet;
                headTweet = new Tweet(id,timestamp);
                headTweet->next = t;
            }
    };
    
    unordered_map<int,User*> users;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(users.find(userId)==users.end())
            users[userId] = new User(userId);
        
        users[userId]->post(tweetId,timestamp);
        timestamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        if(users.find(userId)==users.end())
            return res;
        
        User* user = users[userId];
        unordered_set<int> followed = user->followed;
        
        struct myComparator{
           bool operator()(Tweet *t1, Tweet *t2) 
            { 
                return t1->time < t2->time; 
            } 
        };
        
        priority_queue<Tweet*,vector<Tweet*>,myComparator> q;
        
        for(int user: followed){
            Tweet* tweet = users[user]->headTweet;
            if(tweet)
                q.push(tweet);
        }
        
        int i = 0;
        int n = 10;
        
        while(i<n && !q.empty()){
            Tweet* tweet = q.top();
            res.push_back(tweet->id);
            q.pop();
            if(tweet->next)
                q.push(tweet->next);
            i++;
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(users.find(followerId)==users.end())
            users[followerId] = new User(followerId);
        
        if(users.find(followeeId)==users.end())
            users[followeeId] = new User(followeeId);
        
        users[followerId]->follow(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId)==users.end() || followerId==followeeId)
			return;
        users[followerId]->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

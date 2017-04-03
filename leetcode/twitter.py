#!/usr/bin/env python
import itertools

class User(object):
    def __init__(self):
        self._userId = itertools.count().next
        self._tweets = []
        self._following = []
        self._followers = []

    def addTweet(self, tweetId):
        self._tweets.append(tweetId)

    def removeTweet(self, tweetId):
        self._tweets.remove(tweetId)

    def addFollowing(self, followingId):
        self._following.append(followingId)

    def removeFollowing(self, followingId):
        self._following.remove(followingId)

    def addFollower(self, followerId):
        self.follower.append(followerId)

    def removeFollower(self, followerId):
        self.follower.remove(followerId)

class Twitter(object):
    def __init__(self):
        self._users = {}
        self._allTweets = {}

    def postTweet(self, userId, tweetId):
       self._users[userId].addTweet(tweetId) 
       self._allTweets.append((userId, tweetId))

    def getNewsFeed(self, userId):
        userFollowingList = self._user[userId]._following
        result = [x[0] for x in self._allTweets.reverse() if x[0] == userId or x[0] in userFollowingList ]
        return result


    def follow(self, followerId, followeeId):
        if followerId not in _users.keys():
            newuser = User(folllowerId)
            self._users[followerId] = newuser
        if followeeId not in _users.keys():
            newuser = User(followeeId)
            self._users[followeeId] = newuser
        self._users[followerId].addFollowing(follweeId)

    def unfollow(self, follwerId, follweeId):
        self._users[followerId].removeFollower(followeeId)

def main():
    newUser = User()
    newUser.addTweet(1)
    twitter = Twitter()
    twitter.postTweet(1, 1)
    twitter.follow(1, 2)
    twitter.postTweet(2, 2)
    print twitter.getNewsFeed(1)

main()


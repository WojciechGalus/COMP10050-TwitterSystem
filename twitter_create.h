#ifndef MAIN_C_TWITTER_CREATE_H
#define MAIN_C_TWITTER_CREATE_H

#endif //MAIN_C_TWITTER_CREATE_H

//Max length of:
#define TWEET_LENGTH 280
#define USERNAME_LENGTH 20
#define MAX_FOLLOW 30
#define MAX_TWEETS 10



typedef struct twitter_user{
    char username[USERNAME_LENGTH];
    char followerList[MAX_FOLLOW][USERNAME_LENGTH];
    int followerNum;
    char followingList[MAX_FOLLOW][USERNAME_LENGTH];
    int followingNum;
    int userid;         //when printing accounts that are followable, current user and followable userID cannot match
}user;

typedef struct tweet{
    char msg[TWEET_LENGTH];
    struct twitter_user usr;    //author of tweet is a struct user
}tweet;

typedef struct twitter_system{
    struct tweet post;
    struct twitter_user user;
}twitter;

void create_twitter_system(twitter * twitter_system);   //function never used

void fgetsDebug();         //function to fgets the leftover "\n" from printf statements that would cause fgets to not wait for user input

void printNewsFeed(user, tweet newsFeed[],int tweetNum);    //function display News Feed

void unfollowAll(user);     //user following list is erased

void loseFollowers(user);   //user follower list is erased
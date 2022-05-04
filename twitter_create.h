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

    int userid;
}user;

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    struct twitter_user usr;
}tweet;

typedef struct twitter_system{
    struct tweet post;
    struct twitter_user user;
}twitter;

void create_twitter_system(twitter * twitter_system);

void fgetsDebug();

void printNewsFeed(user, tweet newsFeed[],int tweetNum);
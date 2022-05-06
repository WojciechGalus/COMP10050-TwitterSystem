#include <stdio.h>
#include "twitter_create.h"
#include <string.h>

void fgetsDebug() {         //when fgets is called it read "\n" as an input and would continue rather than wait for user's input
    char first_input_gets_skipped[2];
    fgets(first_input_gets_skipped, 2,
          stdin);      //calling it before an fgets call, means user can enter information correctly
}

void printNewsFeed(user user1, tweet newsFeed[],int tweetNum){
    printf("\nNEWS FEED");
    int control=0,i=0,j=tweetNum;   //control checks there are more posts before decrementing 'j'
                                    //i is a counter for the number of tweets posted
                                    //j sorts through newsFeed array positions, starting from the last position i.e. most recent tweet

    //while there are more tweets to check and 10 tweets we're not printed
    while((control==0) && (i!=MAX_TWEETS)){
        //if current user posted most recent tweet, and it is not erased
        if((strcmp(newsFeed[j].usr.username,user1.username)==0) && (strcmp(newsFeed[j].msg,"\n")!=0)){
            printf("\n------------------------------------------");
            //print the author's username and tweet
            printf("\n%s\n%s",user1.username,newsFeed[j].msg);
            printf("------------------------------------------");
            //increment 'posts printed' counter
            i++;
        }
        //search through current user's followed accounts
        for(int u=0;u < user1.followingNum;u++) {
            //if followed account is the author of most recent tweet, and it is not erased
            if((strcmp(newsFeed[j].usr.username,user1.followingList[u])==0) && (strcmp(newsFeed[j].msg,"\n")!=0)){
                printf("\n------------------------------------------");
                //print the author's username and tweet
                printf("\n%s\n%s",newsFeed[j].usr.username,newsFeed[j].msg);
                printf("------------------------------------------");
                //increment 'posts printed' counter
                i++;
            }
        }
        //j==0 if current post is the last in newsFeed
        if(j==0){
            //control changes to break loop, no more tweets to print
            control=1;
        }
        //move to next newsFeed element
        else{
            j--;
        }}}//end of printNewsFeed

void unfollowAll(user user1){
    //go through list of followers
    while(user1.followerNum != 0){
        //erase last element in list and decrement followerNum
        strcpy(user1.followerList[user1.followerNum], "\t");
        user1.followerNum--;
    }
}

void loseFollowers(user user1){
    //go through list of accounts being followed
    while(user1.followingNum !=0) {
        //erase last element in array and decrement followingNum
        strcpy(user1.followingList[user1.followingNum], "\t");
        user1.followingNum--;
    }
}

void create_twitter_system(twitter * twitter_system){}  //function never used


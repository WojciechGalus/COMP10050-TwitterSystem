#include <stdio.h>
#include "twitter_create.h"
#include <string.h>

void printFollowable(user followerList){

}

void fgetsDebug(){
    char first_input_gets_skipped[2];
    fgets(first_input_gets_skipped,2,stdin);
}

void printNewsFeed(user user1, tweet newsFeed[],int tweetNum){
    printf("\nNEWS FEED\n");
    int control=0,i=0,j=tweetNum,u=0;
    //user= username, follower List/Num, following List/Num
    //newsFeed array of = twitter usr, id, char msg[]
    while((control==0) && (i!=MAX_TWEETS)){

        if(strcmp(newsFeed[j].usr.username,user1.username)==0){
            printf("\n%s",newsFeed[j].msg);
            printf("\nSTATS:\nu:%d\nj:%d\ni:%d\ncontrol:%d",u,j,i,control);
            printf("\n------------------------------------------\n");
            i++;
        }
        for(u=0;u < user1.followingNum;u++) {
            if(strcmp(newsFeed[j].usr.username,user1.followingList[u])==0){
                printf("\n%s",newsFeed[j].msg);
                printf("\nSTATS:\nu:%d\nj:%d\ni:%d",u,j,i);
                printf("\n------------------------------------------\n");
                i++;
            }
        }

        if(j==0){       //end of news feed, no more posts left
            control=1;
        }
        else{
            j--;
        }
    }
}









void create_twitter_system(twitter * twitter_system){
    //??????????
}


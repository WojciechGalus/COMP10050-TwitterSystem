#include <stdio.h>
#include "twitter_create.h"
#include <string.h>

void main(void) {



    int userbase;
    int compret,check, compunf;
    int skip=0;
    printf("Greetings GAMER!111!! How many users do you want?\n");
    scanf("%d", &userbase);
    user userList[userbase];
    tweet newsFeed[MAX_TWEETS];
    int tweetNum=0;

    char PoI[USERNAME_LENGTH];
    char CoI[USERNAME_LENGTH];

    fgetsDebug();
    for(int i=0;i<userbase;i++) {
        printf("Create a user...\n");
        fgets(userList[i].username,USERNAME_LENGTH, stdin);
        userList[i].userid=i+1;
        userList[i].followingNum=0;
        userList[i].followerNum=0;
    }
    printf("\nUsers Created :^D");

    int k = 0;
    int input=0;
    while(k<userbase){
        user * currentUser = &userList[k];
        printf("\nCurrently logged in as:\n@%s\nFollowers:%d\nFollowing:%d\n",userList[k].username, userList[k].followerNum, userList[k].followingNum);
        printf("\n\nPlease select one of the following options:\n"
               "|Post Tweet (1)|    |News Feed (2)|\t|Follow (3)|\t|Unfollow (4)|\n|Delete Account (5)|    |End Session (6)|     |Exit to Desktop (7)|\n");
        scanf("%d",&input);
        if((input<1) || (input>7)){
            printf("Incorrect operation, process terminating\n");
            input=7;
        }

        if(input==1){
            printf("you post");
            //typedef struct tweet{
            //    int id;
            //    char msg[TWEET_LENGTH];
            //    struct twitter_user usr;
            //}tweet;

            printf("\nWhat's on your mind?\n(Press 'Enter' now if you wish to go back)\n\n",userList[k].username);
            fgetsDebug();
            fgets(newsFeed[tweetNum].msg,TWEET_LENGTH,stdin);
            if(strcmp(newsFeed[tweetNum].msg,"\n")!=0) {
                newsFeed[tweetNum].usr = userList[k];
                newsFeed[tweetNum].id = tweetNum;
                tweetNum++;
            }

        }
        if(input==2){
            printf("news feed");
            printNewsFeed(userList[k], newsFeed, tweetNum);
        }



        if(input==3){

            printf("follow\n");
            printf("\nList of users that can be followed:\nUser ID | Username\n");
                for(int i=0;i<userbase;i++){
                    check=0;
                        for (int j = 0; j < currentUser->followingNum; j++) {
                            compret = strcmp(userList[i].username, userList[k].followingList[j]);
                            //check++ if strcmp==0
                            //let j increment if not
                            if(compret==0){
                                check=1;
                            }
                        }
                        if ((userList[i].userid != currentUser->userid) && (check==0)) {
                                    printf("  %d       %s", userList[i].userid, userList[i].username);
                        }
                }
            fgetsDebug();
            while(skip==0) {

                printf("\nInput the username of the account you wish to follow or press 'Enter' to skip:\n");
                fgets(PoI,USERNAME_LENGTH,stdin);
                if (strcmp(PoI, "\n") ==0 ){
                    skip=1;
                }
                else {
                    check = 0;
                    for (int i = 0; i < userbase; i++) {
                        //find user in userbase with strcmp
                        compret = strcmp(PoI, userList[i].username);
                        if (compret == 0) {
                            //user "k" follows user "i"
                            strcpy(userList[k].followingList[userList[k].followingNum], userList[i].username);
                            userList[k].followingNum++;
                            //user "i" is followed by user "k"
                            strcpy(userList[i].followerList[userList[i].followerNum], userList[k].username);
                            userList[i].followerNum++;
                            printf("\nfollowed user:\n%s\n%d   %d", userList[i].username, userList[i].followerNum,
                                   userList[i].followingNum);
                            i = userbase;
                            check = 1;
                        }
                    }
                    if (check == 0) {
                        perror("\nEntered username could not be found");
                    }
                }

            }
            skip=0;

            printf("\n essa");
        }


        int unfollow;
        if(input==4){
            printf("unfollow\n");
            printf("\nList of users that can be unfollowed:\n");
            for(int i=0;i<currentUser->followingNum;i++){
                printf("%s",userList[k].followingList[i]);
            }
            fgetsDebug();
            while(skip==0) {

                printf("\nInput the username of the account you wish to unfollow or press 'Enter' to skip:\n");
                fgets(CoI, USERNAME_LENGTH, stdin);
                if (strcmp(CoI, "\n") ==0 ){
                    skip=1;
                }
                else{
                    check = 0;
                    for (int i = 0; i < userList[k].followingNum; i++) {
                        //find user in userbase with strcmp
                        compret = strcmp(CoI, userList[k].followingList[i]);
                        if (compret == 0) {
                            unfollow=i;

                            printf("\nunfollowed user:%s   %d   %d", userList[k].followingList[i], userList[i].followerNum,
                                   userList[i].followingNum);
                            //user "k" unfollows account "i" in followingList
                            //account "i" gets overwritten by last account in list and list size is reduced by 1
                            strcpy(userList[k].followingList[i], userList[k].followingList[userList[k].followingNum]);
                            userList[k].followingNum--;
                            //int unfollowCheck=userList[unfollow].followerNum;
                            //userList[1].followerNum--;
                            printf("\nunfollowed user:%s   %d   %d", userList[k].followingList[i], userList[i].followerNum,
                                   userList[i].followingNum);

                            int m;
                            for(m=0;m<userbase;m++){
                                compret = strcmp(CoI, userList[m].username);
                                if(compret==0){     //user[m] is account to be unfollowed, look through user[m] follower list and find user[k]
                                    for(int h=0;h<userList[m].followerNum;h++) {
                                        compunf = strcmp(userList[k].username, userList[m].followerList[h]);
                                        if(compunf == 0) {
                                            //account "k" gets overwritten by last account in list and list size reduced by 1
                                            strcpy(userList[m].followerList[h],
                                                   userList[m].followerList[userList[m].followerNum]);
                                            userList[m].followerNum--;
                                            printf("\n hello %s", userList[unfollow].username);
                                            m = userbase;
                                        }
                                    }
                                }
                            }




                            //user "i" is unfollowed by user "k"
                            //unfollowCheck=userList[unfollow].followerNum;
                            //find account "k" in account "i" followerList
                            //for(int m=0;m < unfollowCheck;m++){
                                //compret = strcmp(CoI, userList[unfollow].followerList[m]);
                                //userList[1].followerNum--;
                                //if(compret==0){
                                    //account "k" gets overwritten by last account in list and list size reduced by 1
                                    //strcpy(userList[unfollow].followerList[m], userList[unfollow].followerList[userList[unfollow].followerNum]);
                                    //printf("\n hello %s",userList[unfollow].username);
                                    //m=MAX_FOLLOW;
                                //}
                            //}
                            i = userbase;
                            check = 1;
                        }
                    }
                    if (check == 0) {
                        perror("\nEntered username could not be found");
                    }
                }
            }
            skip=0;

        }

        if(input==5){
            printf("delete account");
        }
        if(input==6){
            printf("next user");
            k++;
        }
        if(input==7){
            printf("exit");
            break;
        }
    }
}


#include <stdio.h>
#include "twitter_create.h"
#include <string.h>
//to do: unfollow function, follow function, delete user function(?)

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
                            //check++ if strcmp==0
                            //let j increment if not
                            if(strcmp(userList[i].username, userList[k].followingList[j])==0){
                                check=1;
                            }
                        }
                        if ((userList[i].userid != currentUser->userid) && (check==0) && (strcmp("\t",userList[i].username)!=0)) {
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
            printf("delete account\n");
            char deleteUser[USERNAME_LENGTH];
            fgetsDebug();
            printf("Are you sure you wish to delete the account:\n%sEnter your username to confirm or press 'Enter' to skip.\n",userList[k].username);
            fgets(deleteUser,USERNAME_LENGTH,stdin);
            if(strcmp(deleteUser,userList[k].username)==0){
                printf("\nuser deleted");

                //erase tweets from newsfeed
                for (int i = 0; i < tweetNum; ++i) {          //go through all tweets
                    //if posted by user to be deleted
                    if(strcmp(deleteUser,newsFeed[i].usr.username)==0){
                        //erase message
                        strcpy(newsFeed[i].msg,"\n");
                    }
                }

                //userbase loses deleted user as a follower
                if(userList[k].followingNum>0){
                    for(int m=0;m<userbase;m++){
                        for(int h=0;h<userList[m].followerNum;h++) {
                            compunf = strcmp(deleteUser, userList[m].followerList[h]);
                            if(compunf == 0) {
                            //account "k" gets overwritten by last account in list and list size reduced by 1
                                strcpy(userList[m].followerList[h],
                                   userList[m].followerList[userList[m].followerNum]);
                                userList[m].followerNum--;
                                printf("\n hello", userList[unfollow].username);
                                h = userList[m].followerNum+1;
                                }
                            }
                    }
                }
                if(userList[k].followerNum>0) {
                    //look through userbase
                    for (int m = 0; m < userbase; m++) {
                        //search through each user's list of accounts they follow
                        for(int i=0;i<userList[m].followingNum;i++){
                            //if they follow the deleted user
                            if(strcmp(deleteUser,userList[m].followingList[i])==0){
                                //overwrite deleted user in list of following accounts with the last account followed
                                strcpy(userList[m].followingList[i],
                                       userList[m].followingList[userList[m].followingNum]);
                                //user[m] follows 1 less account
                                userList[m].followingNum--;
                                i=userList[m].followingNum+1;
                            }
                        }
                    }
                }

                while(userList[k].followerNum != 0){
                    strcpy(userList[k].followerList[userList[k].followerNum], "\t");
                    userList[k].followerNum--;
                }

                //deleted account loses its list of accounts being followed
                while(userList[k].followingNum !=0) {    //go through list of accounts being followed
                    strcpy(userList[k].followingList[userList[k].followingNum], "\t");
                    userList[k].followingNum--;
                }


                //deleted account's username erased
                strcpy(userList[k].username,"\t");

                printf("\n Account terminated.");
                k++;


            }
            else{
                printf("\nAccount NOT terminated.");
            }

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


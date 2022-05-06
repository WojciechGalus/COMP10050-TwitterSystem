//Twitter System - Wojciech Galus
//19462882
//wojciech.galus@ucdconnect.ie

#include <stdio.h>
#include "twitter_create.h"
#include <string.h>


void main(void) {
    //VARIABLES
    int userbase;                           //number of users
    int compReturn, compFollower;           //stores strcmp() results
    int skip;                               //changes to 1 when user wishes to stop while loop
    int check;                              //changes to 1 when username entered by user was found
    int k = 0;                              //iterates over userbase so each user gets a turn
    int input=0;                            //user's input starts each function

    //will store usernames entered by current player
    char deleteUser[USERNAME_LENGTH];
    char followUsername[USERNAME_LENGTH];
    char unfollowUsername[USERNAME_LENGTH];

    //CREATE USERS
    printf("How many users do you wish to create?\n");
    scanf("%d", &userbase);
    user userList[userbase];                    //array of users created
    tweet newsFeed[MAX_TWEETS];                 //array of tweets created
    int tweetNum=0;

    fgetsDebug();                               //fgets did not wait for user input if most recent char was "\n"
    for(int i=0;i<userbase;i++) {               //create as many users as inputted on Line 22
        printf("Enter a username\n");
        fgets(userList[i].username,USERNAME_LENGTH, stdin); //get username
        userList[i].userid=i+1;                 //userid assigned
        userList[i].followingNum=0;             //all users start with 0 followers and follow 0 accounts themselves
        userList[i].followerNum=0;
    }
    printf("\nUser creation finished.\n");

    //TWITTER SYSTEM
    while(k<userbase){
        user * currentUser = &userList[k];
        //show user's account info and ask what he/she wants to do
        printf("\nCurrently logged in as:\t%sFollowers:%d\nFollowing:%d",userList[k].username, userList[k].followerNum, userList[k].followingNum);
        printf("\n\nPlease select one of the following options:\n"
               "|Post Tweet (1)|    |News Feed (2)|\t|Follow (3)|\t|Unfollow (4)|\n|Delete Account (5)|    |End Turn (6)|     |Exit System (7)|\n");
        scanf("%d",&input);     //read/store user input

        if((input<1) || (input>7)){     //invalid input
            printf("Incorrect operation, process terminating\n");
            input=7;
        }

        //POST TWEET
        if(input==1){
            printf("\nWhat's on your mind?\n(Press 'Enter' now if you wish to go back)\n\n",userList[k].username);
            fgetsDebug();
            fgets(newsFeed[tweetNum].msg,TWEET_LENGTH,stdin);   //get string and store in most recent newsfeed position
            if(strcmp(newsFeed[tweetNum].msg,"\n")!=0) {        //if user does not wish to skip
                newsFeed[tweetNum].usr = userList[k];           //tweet author is currently playing user
                tweetNum++;                                     //number of tweets increased
            }
        }

        //PRINT NEWSFEED
        if(input==2){
            printNewsFeed(userList[k], newsFeed, tweetNum);     //function prints news feed
        }

        //FOLLOW
        if(input==3){
            printf("\nList of users that can be followed:\n");
            //search through userbase
            for(int i=0;i<userbase;i++){
                check=0;                        //if check!=0, username 'i' will not print

                //search through current user's list of accounts being followed
                for (int j = 0; j < currentUser->followingNum; j++) {
                    if(strcmp(userList[i].username, userList[k].followingList[j])==0){
                        check=1;                //if user 'i' is in current user's following list, do NOT print
                    }
                }

                //print user 'i' username if: it does not belong to current user, account is followable, user was deleted
                if ((userList[i].userid != currentUser->userid) && (check==0) && (strcmp("\t",userList[i].username)!=0)) {
                    printf("%s", userList[i].username);
                }
            }

            fgetsDebug();
            skip=0;
            while(skip==0) {    //User can follow accounts until he/she chooses to skip
                printf("\nInput the username of the account you wish to follow or press 'Enter' to skip:\n");
                fgets(followUsername,USERNAME_LENGTH,stdin);      //store input in followUsername
                if (strcmp(followUsername, "\n") ==0 ){                             //check if user wants to skip
                    skip=1;
                }
                else {
                    check = 0;         //if check == 0 after search, entered username was not found in userbase
                    //find user in userbase with strcmp
                    for (int i = 0; i < userbase; i++) {
                        compReturn = strcmp(followUsername, userList[i].username);  //strcmp returns int
                        if (compReturn == 0) {                                      //if user 'i' username is the same as inputted by user
                            //current user follows user "i"
                            strcpy(userList[k].followingList[userList[k].followingNum], userList[i].username);
                            userList[k].followingNum++;
                            //user "i" is followed by user "k"
                            strcpy(userList[i].followerList[userList[i].followerNum], userList[k].username);
                            userList[i].followerNum++;
                            i = userbase;   //user found, for loop can stop
                            check = 1;      //entered username was found
                        }
                    }
                    if (check == 0) {       //if entered username was not found
                        perror("\nEntered username could not be found");
                    }}}}//end of follow segment

        //UNFOLLOW
        if(input==4){
            printf("\nList of users that can be unfollowed:\n");
            //search through current user's list of account followed
            for(int i=0;i<currentUser->followingNum;i++){
                printf("%s",userList[k].followingList[i]);
            }
            fgetsDebug();
            skip=0;
            while(skip==0) {    //repeat until user skips
                printf("\nInput the username of the account you wish to unfollow or press 'Enter' to skip:\n");
                fgets(unfollowUsername, USERNAME_LENGTH, stdin);
                if (strcmp(unfollowUsername, "\n") ==0 ){
                    skip=1;     //if only 'Enter' was pressed, skip
                }
                else{
                    check = 0;  //if check==1, entered username was found in followingList and was unfollowed
                    for (int i = 0; i < userList[k].followingNum; i++) {
                        //find user in userbase with strcmp
                        compReturn = strcmp(unfollowUsername, userList[k].followingList[i]);
                        //user found
                        if (compReturn == 0) {
                            //current user unfollows account "i" in followingList
                            //account "i" gets overwritten by last account in list and followingNum is reduced by 1
                            strcpy(userList[k].followingList[i], userList[k].followingList[userList[k].followingNum]);
                            userList[k].followingNum--;
                            //search through userbase and find user being unfollowed
                            for(int m=0;m<userbase;m++){
                                compReturn = strcmp(unfollowUsername, userList[m].username);
                                if(compReturn==0){     //user[m] is account to be unfollowed
                                    //look through user[m] follower list and find current user
                                    for(int h=0;h<userList[m].followerNum;h++) {
                                        compFollower = strcmp(userList[k].username, userList[m].followerList[h]);
                                        if(compFollower == 0) {
                                            //account "k" gets overwritten by last account in list and list size reduced by 1
                                            strcpy(userList[m].followerList[h],
                                                   userList[m].followerList[userList[m].followerNum]);
                                            userList[m].followerNum--;
                                            m = userbase;   //if account[m] no longer has current user as follower, finish search
                                        }}}}
                            i = userbase;   //finish searching userbase if unfollowUsername exists in current user's followingList
                            check = 1;      //username entered was found
                        }}
                    if (check == 0) {
                        perror("\nEntered username could not be found");
                    }}}}//end of unfollow segment

        //DELETE ACCOUNT
        if(input==5){
            fgetsDebug();
            printf("Are you sure you wish to delete the account:\n%sEnter your username to confirm or press 'Enter' to skip.\n",userList[k].username);
            fgets(deleteUser,USERNAME_LENGTH,stdin);
            //username entered is compared to current user's username
            if(strcmp(deleteUser,userList[k].username)==0){
                //erase tweets from newsfeed
                //go through all tweets
                for (int i = 0; i < tweetNum; ++i) {
                    //if posted by user to be deleted
                    if(strcmp(deleteUser,newsFeed[i].usr.username)==0){
                        //erase message
                        strcpy(newsFeed[i].msg,"\n");
                    }
                }

                //userbase loses deleted user as a follower, if user follows anyone
                if(userList[k].followingNum>0){
                    //search through userbase
                    for(int m=0;m<userbase;m++){
                        //search through every user's follower list
                        for(int h=0;h<userList[m].followerNum;h++) {
                            compFollower = strcmp(deleteUser, userList[m].followerList[h]);
                            //if user being deleted is in user[m] follower list
                            if(compFollower == 0) {
                            //current user gets overwritten by last account in follower list and follower number reduced by 1
                                strcpy(userList[m].followerList[h],
                                   userList[m].followerList[userList[m].followerNum]);
                                userList[m].followerNum--;
                                h = userList[m].followerNum+1;  //stop searching through user[m] follower list once current user is found
                                }
                            }}}
                //userbase stops following deleted user, if user has any followers
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
                                //reduce number of user[m] following accounts by 1
                                userList[m].followingNum--;
                                i=userList[m].followingNum+1;   //stop searching through user[m] following list once current user is found
                            }}}}

                unfollowAll(userList[k]);   //accounts in deleted user's followingList erased

                loseFollowers(userList[k]); //accounts in deleted user's followerList erased

                //deleted account's username erased
                strcpy(userList[k].username,"\t");
                printf("\n Account terminated.");
                k++;    //next user's turn to "play"
            }
            //if entered username does not match current user's name
            else{
                printf("\nAccount NOT terminated.");
            }

        }

        //NEXT USER
        if(input==6){
            printf("\n\nNext user's turn");
            k++;    //position in user list incremented
        }

        //EXIT TWITTER SYSTEM
        if(input==7){
            printf("\n\nExiting");
            break;                          //end program
        }
    }
}


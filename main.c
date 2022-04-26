#include <stdio.h>

int main() {
    typedef struct twitter_user{
        char username[20];
        int followerNum;
        int followingNum;
    }user;

    struct tweet{
        int tweetId;
        char tweetString[280];
        struct twitter_user author;
    };

    struct twitter_system{
        struct tweet post;
        struct twitter_user user;
    };


    int userbase;
    printf("Greetings GAMER!111!! How many users do you want?\n");
    scanf("%d", &userbase);
    user userList[userbase];

    for(int i=0;i<userbase;i++) {
        printf("Create a user...\n");
        scanf("%s", &userList[i].username);
        userList[i].followingNum=0;
        userList[i].followerNum=0;
    }
    printf("\nUsers Created :^D");
    //for(int i=0;i<userListSize;i++){
    //    printf("-------------------\n");
    //    printf("@%s\nFollowers:%d\nFollowing:%d\n",userList[i].username, userList[i].followerNum, userList[i].followingNUm);
    //}
    int j = 0;
    int input=0;
    while(j<userbase){
        printf("\nCurrently logged in as:\n@%s\nFollowers:%d\nFollowing:%d\n",userList[j].username, userList[j].followerNum, userList[j].followingNum);
        printf("\n\nPlease select one of the following options:\n"
               "Post Tweet (1)\tNews Feed (2)\tFollow (3)\tUnfollow (4)\nDelete Account (5)\tEnd Session (6)\tExit to Desktop (7)\n");
        scanf("%d",&input);
        if((input<1) || (input>7)){
            printf("Incorrect operation, process terminating\n");
        }
        if(input==1){
            printf("you post");
        }
        if(input==2){
            printf("news feed");
        }
        if(input==3){
            printf("follow");
        }
        if(input==4){
            printf("unfollow");
        }
        if(input==5){
            printf("delete account");
        }
        if(input==6){
            printf("next user");
        }
        if(input==7){
            printf("exit");
        }






        j=10;
    }


    return 0;
}


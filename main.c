#include <stdio.h>

int main() {
    typedef struct twitter_user{
        char username[20];
        int followerNum;
        int followingNUm;
    }user;

    int userListSize;
    printf("Greetings GAMER!111!! How many users do you want?\n");
    scanf("%d", &userListSize);
    user userList[userListSize];

    for(int i=0;i<userListSize;i++) {
        printf("Create a user...\n");
        scanf("%s%d%d", &userList[i].username, &userList[i].followerNum, &userList[i].followingNUm);
    }

    for(int i=0;i<userListSize;i++){
        printf("-------------------\n");
        printf("@%s\nFollowers:%d\nFollowing:%d\n",userList[i].username, userList[i].followerNum, userList[i].followingNUm);
    }









    return 0;
}


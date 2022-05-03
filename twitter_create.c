#include <stdio.h>
#include "twitter_create.h"
#include <string.h>

void printFollowable(user followerList){

}

void fgetsDebug(){
    char first_input_gets_skipped[2];
    fgets(first_input_gets_skipped,2,stdin);
}

void quickSort(char array[][USERNAME_LENGTH], int first, int last){
    int i, j;                                    //i and j used for array indexes
    char *pivot;                                 //pointer to string in array used as pivot
    char swap[USERNAME_LENGTH];                //buffer array for swapping strings

    //assign variables with first and last index of array
    i = first;
    j = last;

    pivot = array[(first + (last - first)/2)];   //pivot is median element in array

    if(first<last)
    {
        while((strcmp(array[i],pivot) < 0) && (i <= last) && (j > i)) {         //while current string starts with lower ASCII code value than pivot
            //and i has not passed last index or reached index j
            i++;                                                                    //increment i
        }
        while((strcmp(array[j],pivot) > 0) && (j >= first) && (j > i)) {        //while current string starts with higher ASCII code value than pivot
            //and j has not passed first index or reached index i
            j--;                                                                    //decrement j
        }
        //While loops stop once element at i should be below pivot and element at j should be above pivot

        if(i <= j) {
            strcpy(swap, array[i]);             //swap string at i with string at j
            strcpy(array[i], array[j]);         //using buffer array
            strcpy(array[j], swap);
            i++;                                            //move indexes after swap
            j--;
        }
    }

    //Function calls upon itself
    if(first < j) {
        quickSort(array, first, j); //using ranges (first -> j)
    }
    if(i < last) {
        quickSort(array, i, last);  //using ranges (i -> last)
    }
}











void create_twitter_system(twitter * twitter_system){

}


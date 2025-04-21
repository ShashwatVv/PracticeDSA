// Given an array of integers arr, return true if the number 
// of occurrences of each value in the array is unique or false otherwise.

/*
    Constraints:

    1 <= arr.length <= 1000 
    -1000 <= arr[i] <= 1000
*/

#include<stdbool.h>
bool uniqueOccurrences(int* arr, int arrSize) {
    int visited[2001] = {0}; //2001 is the max possible set of values
    int seenFreq[1001] = {0}; // 1001 is the max arrSize + 1 
    
    // traverse the array and increment the index+1000
    // in visited, that is equal to arr[i]
    for (int i=0; i<arrSize; i++)
    {
        int idx_to_look = arr[i] + 1000;
        visited[idx_to_look] +=1;   
    }
    for(int i=0; i<2001; i++)
    {
        int freq = visited[i];
        if(freq>0)
        {
            if (seenFreq[freq]>0) return false;
            seenFreq[freq]++;
        }
    }
    return true;
}
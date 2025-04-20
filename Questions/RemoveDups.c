/* Leetcode easy: #27 */

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
 */


#include<stdio.h>

int remove_element(int *nums, int numsSize, int val);

int main()
{
    int arr[8] = {1, 2, 3 , 2, 3, 5, 3, 6};
    int k = remove_element(arr, 8, 3);
    printf("The number of valid values are: %d\n", k);
    printf("The array after dupes removal: ");
    for(int i=0; i<8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int remove_element(int *nums, int numsSize, int val)
{
    int write_ptr = 0;
    for(int i=0; i<numsSize; i++)
    {
        // if array value is not same as 
        // val, push it towards left
        if(val != nums[i])
        {
            nums[write_ptr] = nums[i];
            write_ptr +=1;
        }
    }
    /* return write ptr as its value indicate the number of valid values */
    return write_ptr;
}
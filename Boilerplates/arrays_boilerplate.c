// array use case

#include <stdio.h>

#define MAX_SIZE    10

/* Insert at end */
void insert_end(int arr[], int* size, int val)
{
    if(*size < MAX_SIZE)
    {
        arr[*size] = val;
        *size += 1;
    }
}


/* Insert at a position */

void insert_at(int arr[], int *size, int val, int index)
{
    if ( (index <= *size) && (*size < MAX_SIZE) )
    {
        int N = *size - 1;
        for (int i=N; i>=index; i--)
        {
            arr[i+1] = arr[i];
        }
        /* Now we can populate the index */
        arr[index] = val;
        
        /* update size */
        *size +=1;
    }
}

/* Delete at index */

void delete_at(int arr[], int *size, int index)
{
    if( (0 == *size) || (index >= *size) ) return;

    for(int i = index; i < *size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    *size = *size - 1;
}


/* Search for an element */
int search_element(int arr[], int size, int key)
{
    int index = -1;
    for (int i=0; i<size; i++)
    {
        if(key == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

/* print array */
void print_array(int arr[], int size)
{
    if(size == 0)
    {
        printf("Empty array!\n");
        return;
    }
    printf("The array is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int A[MAX_SIZE];
    int size = 0;
 
    /* Inserting 1, 2 and 3 from end */
    printf("Insert new elements:---------> \n");
    insert_end(A, &size, 1);
    insert_end(A, &size, 2);
    insert_end(A, &size, 3);
    /* print elements of array */
    print_array(A, size);
     
    /* Inserting at 2nd and 3rd positions */
    printf("Inserting at 2nd and 3rd indices:----------> \n");
    insert_at(A, &size, 4, 2);
    insert_at(A, &size, 5, 3);
    /* print elements of array */
    print_array(A, size);

    /* Searching for element */
    printf("Searching for element 4:----------> \n");
    printf("The array element 4 is at index:%d\n", search_element(A, size, 4));

    /* deleting at index 2 */
    printf("Delete element at index 2:----------> \n");
    delete_at(A, &size, 2);
    /* print elements of array */
    print_array(A, size );
    
    printf("All operations are successful now!\n");
    return 0;
}
int climbStairs(int n) {
    int *arr = (int*)malloc((n+1)*sizeof(int));
    if(n<2) return 1;
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<n+1; i++)
    {
        arr[i] = arr[i-1] + arr[i-2]; 
    }

    return arr[n];
}

/*
You climb either 1 step or 2 steps...
if your first step is of size 1, you can cover remaining
steps in let's say m ways....
now if your first step is of size 2, you can cover remaining steps in 
, let's say in n ways...

so total ways would be m+n such ways...

in that scenario, let's say T(n) denotes distinct ways to reach n steps

then T(n) = T(n-1) steps , if first size is 1...
            +
            T(n-2) if first step size is 2....
So T(n) = T(n-1) + T(n-2)...

if solved recursively, it will be explode .....

we will use an array
Arr[n+1] to store T[n], starting from Arr[0] having value = T[0]

base case: T[0] = 1, T[1] = 1, T[2] = T[1]+T[0]=2
*/



// SUM of two linked lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *result, *last;
    result = NULL;
    last = NULL;
    int carry = 0, sum = 0;

    //It's guaranteed that both lists have atleast an element
    //allocate a temporary node
    struct ListNode *temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    sum = l1->val + l2->val;
    temp1->val = sum%10;
    temp1->next = NULL;
    carry = sum/10;
    result = temp1;
    last = temp1;
    l1 = l1->next;
    l2 = l2->next;
    while((l1 != NULL) && (l2 != NULL))
    {
        sum = carry + l1->val + l2->val;
        carry = sum/10;
        struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp2->val = sum%10;
        temp2->next = NULL;
        last->next = temp2;
        last = temp2;

        //move list 1 and list2 ptrs
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL)
    {
        sum = carry + l1->val;
        carry = sum /10;
        struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp2->val = sum%10;
        temp2->next = NULL;
        last->next= temp2;
        last = temp2;

        l1 = l1->next;
    }
    
    while(l2!= NULL)
    {
        sum = carry + l2->val;
        carry = sum /10;
        struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp2->val = sum%10;
        temp2->next = NULL;
        last->next= temp2;
        last = temp2;

        l2 = l2->next;
    }

    if(carry!=0)
    {
        struct ListNode* temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp2->val = carry;
        temp2->next = NULL;
        last->next= temp2;
        last = temp2;
    }

    return result;
    
}
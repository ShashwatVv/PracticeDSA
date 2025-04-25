//Leetcode 67: Add Binary

#define MAX(a, b) ((a)>(b))?(a):(b)
char* addBinary(char* a, char* b) {
    int la, lb, lr, n, carry, A, B;
    la = strlen(a);
    lb = strlen(b);
    n = MAX(la, lb);
    char *result = (char*)malloc((n+2)*sizeof(char));
    carry = 0;
    result[n+1] = '\0';
    result[0] = '0';
    lr = n;
    
    la=la-1;
    lb =lb-1;
    while(la>=0 && lb>=0)
    {
        A = a[la]-48;
        B = b[lb]-48;
        int sum = carry ^ A ^ B;
        printf("LR: %d A: %d B:%d", lr, A, B);
        printf("\n");
        printf("CARRY: %d\n", carry);
        printf("SUM: %d\n", sum);
        result[lr] = (char)(sum + 48);
        printf("RESULT: %c\n", result[lr]);
        carry = (A&B) | (A&carry) | (B&carry);
        lr--;
        lb--;
        la--;
    }
    while(la>=0)
    {
        A = a[la]-48;
        int sum = carry ^ A;
        carry = A&carry;
        result[lr] = (char)(sum+48);
        lr--;
        la--;
    }
    while(lb>=0)
    {
        B = b[lb]-48;
        int sum = carry ^ B;
        carry = B&carry;
        result[lr] = (char)(sum + 48);
        lr--;
        lb--;
    }
    result[lr] = (char)(carry+48);
    if(result[0]=='0') return &result[1];
    return result;
}
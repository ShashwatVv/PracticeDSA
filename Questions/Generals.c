bool isPalindrome(int x) {
    if (x<0) return false;
    int n = x;
    int reverse = 0;
    while(n>0)
    {
        int remain = n%10;
        //check for overflow: use INT_MAX...defined in limits.h
        if(reverse>(INT_MAX-remain)/10) return false;
        
        reverse = 10*reverse + remain;
        n = n/10;
    }
    if(reverse == x) return true;
    else return false;
    
}

/*
digits = 0
reverse_sum = 0
n = x
while(n>0){
    int remain = n%10;
    reverse_sum = 10*reverse_sum+remain;
    n = n/10;
}
if reverse_sum == x: return false, else return true
*/
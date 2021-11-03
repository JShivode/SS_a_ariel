int isArmstrong(int num){
    int n, temp, r, sum = 0;
    n = num;
    temp = n;
    while(n > 0)    
    {
        r = n % 10;    
        sum = sum + (r * r * r);    
        n = n / 10;    
    }    
    if(temp == sum)
        return 1;
    return 0;
}

int isPalindrome(int num){
    int n = num;
    int new_num = 0;

    while(n > 0) {
        new_num = new_num * 10 + n % 10;
        n = n / 10;
    }

    if(new_num == num) return 1;
    else return 0;
}

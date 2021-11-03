#include <math.h>

int digits(int n) {
    int c = 0;
    while (n != 0) {
        c = c + 1;
        n = n / 10;
    }
    return c;
}

int power(int n, int p){
    if(p == 0 && n != 0) return 1;
    if(p == 1) return n;
    return n * power(n, p-1);
}

int getDigitNum(int n){
    if(n == 0) return 0;
    return 1 + getDigitNum(n / 10);
}

int sumDigitPow(int num, int x){
    if(num / 10 == 0)
     return(power(num, x));
    return power(num % 10, x) + sumDigitPow(num / 10, x);
}

int isArmstrongRecursion(int num) {
    int n = sumDigitPow(num, getDigitNum(num));
    if (num == n) return 1;
    else return 0;
}

int isPalindromeRecursionHelper(int num) {
    int digs = (int)log10(num);
    if (num == 0) return 0;
    return ((num % 10 * pow(10, digs)) + isPalindromeRecursionHelper(num / 10));
}

int isPalindromeRecursion(int num){
    if (num == isPalindromeRecursionHelper(num)) return 1;
    else return 0;
    
}
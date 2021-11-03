#include <stdio.h>
#include "NumClass.h"

int main() {
    int start, end;
    printf("Enter your start number: \n");
    scanf("%d", &start);
    printf("Enter your end number: \n");
    scanf("%d", &end);

    int i;
    printf("Strong numbers are: ");
    for (i = start; i <= end; i++) {
        if (isStrong(i) == 1) printf("%d, ", i);
    }
    printf("\n");
    printf("Armstrong numbers are: ");
    for (i = start; i <= end; i++) {
        if (isArmstrongRecursion(i) == 1) printf("%d, ", i);
    }
    printf("\n");
    printf("Prime numbers are: ");
    for (i = start; i <= end; i++) {
        if (isPrime(i) == 1) printf("%d, ", i);
    }
    printf("\n");
    printf("Palindrome numbers are: ");
    for (i = start; i <= end; i++) {
        if (isPalindromeRecursion(i) == 1) printf("%d, ", i);
    }
    return 0;
}
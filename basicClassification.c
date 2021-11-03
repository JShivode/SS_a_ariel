int isPrime(int num){
    int i;
    for(i = 2; i < num / 2; i++){
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int factorial(int num){
    int sum = 1;
    for(int i = 1; i <= num ; i++) {
        sum = sum * i;
    }
    return sum;
}

int isStrong(int num){
    int sum = 0;
    int n = num;

    while(n > 0) {
        sum += factorial(n % 10);
        n = n / 10;
    }

    if(sum == num) return 1;
    else return 0;
}
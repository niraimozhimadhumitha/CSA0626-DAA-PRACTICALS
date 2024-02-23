#include <stdio.h>
int isPrime(int num, int divisor) {
    if (divisor <= 1)
        return 1; 
    if (num % divisor == 0)
        return 0; 
    return isPrime(num, divisor - 1);
}

void generatePrimes(int currentNum, int limit) {
    if (currentNum > limit)
        return;
    if (isPrime(currentNum, currentNum / 2) == 1)
        printf("%d ", currentNum);
    generatePrimes(currentNum + 1, limit);
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are:\n", limit);
    generatePrimes(2, limit);

    return 0;
}


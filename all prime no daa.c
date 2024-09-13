#include <stdio.h>



// Recursive function to check if a number is prime

int isPrime(int num, int i) {

    if (num <= 2) 

        return (num == 2) ? 1 : 0;  // Base cases

    if (num % i == 0) 

        return 0;  // Divisible by a smaller number

    if (i * i > num) 

        return 1;  // If no divisor found

    return isPrime(num, i + 1);  // Recursive call

}



// Recursive function to print all primes up to n

void printPrimes(int n, int current) {

    if (current > n)

        return;  // Base case

    if (isPrime(current, 2))

        printf("%d ", current);

    printPrimes(n, current + 1);  // Recursive call

}



int main() {

    int n = 50;  // Example limit

    printf("Prime numbers up to %d are: ", n);

    printPrimes(n, 2);  // Start with 2

    printf("\n");

    return 0;

}


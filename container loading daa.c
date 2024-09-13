#include <stdio.h>



int max(int a, int b) {

    return (a > b) ? a : b;

}



// Function to solve the Container Loader Problem

void containerLoader(int weights[], int values[], int n, int capacity) {

    int i, w;

    int dp[n+1][capacity+1];



    // Build the table dp[][]

    for (i = 0; i <= n; i++) {

        for (w = 0; w <= capacity; w++) {

            if (i == 0 || w == 0)

                dp[i][w] = 0;

            else if (weights[i - 1] <= w)

                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);

            else

                dp[i][w] = dp[i - 1][w];

        }

    }



    printf("Maximum value that can be loaded: %d\n", dp[n][capacity]);

}



int main() {

    int weights[] = {10, 20, 30};

    int values[] = {60, 100, 120};

    int capacity = 50;

    int n = sizeof(values) / sizeof(values[0]);

    containerLoader(weights, values, n, capacity);

    return 0;

}


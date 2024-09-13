#include <stdio.h>



// Function to calculate binomial coefficient using Dynamic Programming

int binomialCoeff(int n, int k) {

    int dp[n + 1][k + 1];

    int i, j;



    for (i = 0; i <= n; i++) {

        for (j = 0; j <= (i < k ? i : k); j++) {

            if (j == 0 || j == i) {

                dp[i][j] = 1;

            } else {

                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            }

        }

    }



    return dp[n][k];

}



int main() {

    int n = 5, k = 2;

    printf("Value of C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));

    return 0;

}


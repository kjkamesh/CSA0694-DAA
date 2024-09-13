#include <stdio.h>

#include <limits.h>



#define N 4



int findMinCost(int costMatrix[N][N], int assigned[], int row, int n) {

    int minCost = INT_MAX;

    int i, j;

    for (i = 0; i < n; i++) {

        if (!assigned[i]) {

            assigned[i] = 1;

            int currentCost = costMatrix[row][i] + findMinCost(costMatrix, assigned, row + 1, n);

            minCost = (currentCost < minCost) ? currentCost : minCost;

            assigned[i] = 0;

        }

    }

    return (row == n) ? 0 : minCost;

}



int main() {

    int costMatrix[N][N] = {{9, 2, 7, 8},

                            {6, 4, 3, 7},

                            {5, 8, 1, 8},

                            {7, 6, 9, 4}};

    int assigned[N] = {0};

    int minCost = findMinCost(costMatrix, assigned, 0, N);

    printf("Minimum cost to assign tasks: %d\n", minCost);

    return 0;

}


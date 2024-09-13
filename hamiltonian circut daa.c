#include <stdio.h>

#include <stdbool.h>



#define V 5  // Number of vertices



// Function to check if the vertex v can be added at index pos

bool isSafe(int graph[V][V], int path[], int pos, int v) {

    int i; // Declare loop variable outside

    if (graph[path[pos - 1]][v] == 0)

        return false;



    for (i = 0; i < pos; i++)

        if (path[i] == v)

            return false;



    return true;

}



// Recursive function to find the Hamiltonian Circuit

bool hamCycleUtil(int graph[V][V], int path[], int pos) {

    int v; // Declare loop variable outside

    if (pos == V) {

        return (graph[path[pos - 1]][path[0]] == 1);

    }



    for (v = 1; v < V; v++) {

        if (isSafe(graph, path, pos, v)) {

            path[pos] = v;



            if (hamCycleUtil(graph, path, pos + 1))

                return true;



            path[pos] = -1; // Backtrack

        }

    }



    return false;

}



// Function to solve the Hamiltonian Circuit problem

void hamCycle(int graph[V][V]) {

    int path[V];

    int i; // Declare loop variable outside

    for (i = 0; i < V; i++)

        path[i] = -1;



    path[0] = 0;



    if (hamCycleUtil(graph, path, 1) == false) {

        printf("Solution does not exist\n");

        return;

    }



    printf("Solution exists: Following is the Hamiltonian Circuit:\n");

    for (i = 0; i < V; i++)

        printf("%d -> ", path[i]);

    printf("%d\n", path[0]);

}



int main() {

    int graph[V][V] = { {0, 1, 0, 1, 0},

                        {1, 0, 1, 0, 1},

                        {0, 1, 0, 1, 1},

                        {1, 0, 1, 0, 1},

                        {0, 1, 1, 1, 0} };

    hamCycle(graph);

    return 0;

}


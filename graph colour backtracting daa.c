#include <stdio.h>

#include <stdbool.h>



#define V 4  // Number of vertices



// Function to check if the current color assignment is safe for vertex v

bool isSafe(int graph[V][V], int color[], int v, int c) {

    int i;

    for (i = 0; i < V; i++) {

        if (graph[v][i] && color[i] == c)

            return false;

    }

    return true;

}



// Recursive function to solve the graph coloring problem

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {

    int c; // Declare loop variable outside

    if (v == V)

        return true;



    for (c = 1; c <= m; c++) {

        if (isSafe(graph, color, v, c)) {

            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))

                return true;

            color[v] = 0;  // Backtrack

        }

    }

    return false;

}



// Function to solve the graph coloring problem

void graphColoring(int graph[V][V], int m) {

    int color[V];

    int i; // Declare loop variable outside

    for (i = 0; i < V; i++)

        color[i] = 0;



    if (graphColoringUtil(graph, m, color, 0) == false) {

        printf("Solution does not exist\n");

        return;

    }



    printf("Solution exists: Following are the assigned colors:\n");

    for (i = 0; i < V; i++)

        printf("Vertex %d ---> Color %d\n", i, color[i]);

}



int main() {

    int graph[V][V] = { {0, 1, 1, 1},

                        {1, 0, 1, 0},

                        {1, 1, 0, 1},

                        {1, 0, 1, 0} };

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;

}


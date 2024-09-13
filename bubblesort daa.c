#include <stdio.h>



void bubbleSort(int arr[], int n) {

    int i, j, temp;

    for (i = 0; i < n-1; i++) {

        for (j = 0; j < n-i-1; j++) {

            if (arr[j] > arr[j+1]) {

                temp = arr[j];

                arr[j] = arr[j+1];

                arr[j+1] = temp;

            }

        }

    }

}



int main() {

    int arr[] = {5, 2, 9, 1, 5, 6}; // Change the elements if needed

    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)

        printf("%d ", arr[i]);

    return 0;

}


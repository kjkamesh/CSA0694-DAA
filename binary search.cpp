#include <stdio.h>



int binarySearch(int arr[], int left, int right, int x) {

    if (right >= left) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == x)

            return mid;

        if (arr[mid] > x)

            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);

    }

    return -1;

}



int main() {

    int arr[] = {2, 3, 4, 10, 40}; // Change the elements if needed

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 10; // Change the target number if needed

    int result = binarySearch(arr, 0, n - 1, x);

    if(result == -1)

        printf("Element not present\n");

    else

        printf("Element found at index %d\n", result);

    return 0;

}


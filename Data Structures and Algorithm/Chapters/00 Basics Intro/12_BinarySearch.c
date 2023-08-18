#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int size, int number) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == number) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element) {
    int low, high, mid;
    low = 0;
    high = size - 1;

    // Keep searching until low converges high
    while(low <= high) {
        mid = (low + high) / 2; 

        // Searching Starts
        if(arr[mid] == element) {
            return mid;
        }

        if(arr[mid] < element) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        //  Searching ends
    }
    return -1;
}

int main() {
    // int arr[] = {10, 215, 744, 54, 58};
    // int size = sizeof(arr) / sizeof(int);
    // int element = 88;

    // int searchIndex = linearSearch(arr, size, element);
    // printf("The element %d was found at index %d.\n", element, searchIndex);

    int arr2[] = {10, 23, 35, 40, 44, 46, 58, 78, 100, 150, 795, 1014};
    int size2 = sizeof(arr2) / sizeof(int);
    int element2 = 23;

    int searchIndex2 = binarySearch(arr2, size2, element2);
    printf("The element %d was found at index %d.\n", element2, searchIndex2);
    return 0;
}
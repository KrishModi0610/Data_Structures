#include<stdio.h>
#include<stdlib.h>

int indInsertion(int arr[], int size, int element, int capacity, int index) {
    // Insertion Code

    // Check whether there is space in it or not
    if(size >= capacity) {
        printf("Size is greater than Capacity of Array.\n");
        return 0;
    } 

    // Check whether insertion occurs in-between or not.
    if(index >= size) {
        printf("Index is greater than size.\n");
        return 0;
    }
    // Inserting the element in array
    for(int i = size - 1; i >= index; i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

void display(int arr[], int n) {
    // Traversal In Array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100] = {1, 8, 15, 40, 45};
    int size = 5;
    // int size = 150; // --> To check error
    
    int element = 20;
    int index = 3;
    printf("Before Insertion : ");
    display(arr, size);

    indInsertion(arr, size, element, 100, index);
    // Incrementing the size of array
    size += 1;
    printf("After Insertion : ");
    display(arr, size);

    // ==> Short Exercise to check whether insertion takes place or not.
    // if(indInsertion(arr, size, element, 100, index)) {
    //     size += 1;
    //     printf("After Insertion : ");
    //     display(arr, size);
    // }
    // else {
    //     printf("Error in Insertion!!");
    // }
    
    return 0;
}
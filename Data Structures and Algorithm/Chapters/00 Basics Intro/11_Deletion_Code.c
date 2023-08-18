#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int capacity, int delete_index) {
    
    // Code for Deletion
    if(size > capacity) {
        printf("Size is larger than capacity!!");
        return 0;
    }
    if(delete_index > size) {
        printf("Invalid Input of Delete Index!! \n"); 
        return 0;
    }

    for(int i = delete_index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return 1;  
}

int main() {
    int arr[100] = {10, 25, 35, 45, 78};
    int size = 5;
    int delete_index = 3;
    printf("Before Deletion : ");
    display(arr, size);
    
    indDeletion(arr, size, 100, delete_index);
    // Decrementing Size
    size -= 1;
    printf("After Deletion : ");
    display(arr, size);

    return 0;
}
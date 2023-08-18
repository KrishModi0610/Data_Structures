/* Lecture 6 Notes of Lecture Abstract Data Type and Arrays
ADT == Abstract Data Type
MRF == Minimal Required Functionalities  

Array - Collection of elements accessible by an index
      - Array can't be resized
      - In order to resize the content has to copy to new 
      - Contiguous Memory Location

Types of Arrays --
    1. Static Array - Size cannot be changed
    2. Dynamic Array - Size can be changed
*/

/* Lecture 7 Array ADT implementation Part 1
ADT = Set of values + Set of Operations

Struct myArray{
    int total_Size; --> Memory to be reserved
    int used_Size; --> Memory to be used
};
*/

/*Lecture 8 Array ADT implementation Part 2

*/

#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void show(struct myArray *a) {
    for (int i = 0; i < a->used_size; i++)
    {
         printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a) {
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void createArray(struct myArray *a, int tSize, int uSize) {
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

int main() {
    struct myArray marks;
    createArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);

    return 0;
}
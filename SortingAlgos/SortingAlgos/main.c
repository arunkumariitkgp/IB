//
//  main.c
//  SortingAlgos
//
//  Created by Arun Kumar on 09/01/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b);
void printArray(int a[], int size);

int partition(int a[], int start, int end) {
    
    int pivot = a[end];
    int index = start;
    
    for (int i = index; i < end; i ++) {
        if (a[i] < pivot) {
            swap(&a[i], &a[index]);
            index ++;
        }
    }
    swap(&a[index], &a[end]);
    return index;
}

/*
 When does the worst case O(n^2) of Quicksort occur?
 The answer depends on strategy for choosing pivot. In early versions of Quick Sort where leftmost (or rightmost) element is chosen as pivot, the worst occurs in following cases.
 
 1) Array is already sorted in same order.
 2) Array is already sorted in reverse order.
 3) All elements are same (special case of case 1 and 2)
 
 Since these cases are very common use cases, the problem was easily solved by choosing either a random index for the pivot, choosing the middle index of the partition or (especially for longer partitions) choosing the median of the first, middle and last element of the partition for the pivot. With these modifications, the worst case of Quick sort has less chances to occur, but worst case can still occur if the input array is such that the maximum (or minimum) element is always chosen as pivot.
*/
void quickSort(int a[], int start, int end) {
    
    printf("START IS : %d -- END IS : %d \n",start,end);
    if (start < end) {
        int index = partition(a, start, end);
        printf("INDEX IS : %d \n",index);
        printArray(a, 8);
        quickSort(a, start, index - 1);
        quickSort(a, index + 1, end);
    }
}

void insertionSort(int a[], int n) {
    
    for (int i = 1; i < n; i ++) {
        int value = a[i];
        int emptyPosition = i;
        while (emptyPosition > 0 && a[emptyPosition - 1] > value) {
            a[emptyPosition] = a[emptyPosition - 1];
            emptyPosition --;
        }
        a[emptyPosition] = value;
    }
}

void selectionSort(int a[], int n) {
    
    for (int i = 0; i < n - 1; i ++) {
        int min = i;
        for (int j = i + 1; j < n; j ++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void bubbleSort(int a[], int n) {
    
    _Bool isSwapped = 0;
    for (int j = 0; j < n; j ++) {
        for (int i = 0; i < n - j - 1; i ++) {
            if (a[i] > a[i + 1]) {
                swap(&a[i],&a[i+1]);
                isSwapped = 1;
                //                int temp = a[i];
                //                a[i] = a[i + 1];
                //                a[i + 1] = temp;
            }
        }
        if (!isSwapped) {
            return;
        }
    }
}

void swap(int *a, int *b) {
    
    static int swapCount = 0;
    
    printf("SWAP COUNT : %d\n", ++swapCount);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i ++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    int a[] = {8,2,7,1,3,5,4,6};
    int arr_size = sizeof(a)/sizeof(a[0]);
    
    printf("*********BEFORE SORTING***********");
    printArray(a, arr_size);
    quickSort(a, 0, arr_size - 1);
    printf("*********AFTER SORTING***********");
    printArray(a, arr_size);
    return 0;
}


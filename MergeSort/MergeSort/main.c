//
//  main.c
//  MergeSort
//
//  Created by Arun Kumar on 05/01/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>

/*
The term Space Complexity is misused for Auxiliary Space at many places. Following are the correct definitions of Auxiliary Space and Space Complexity.
 
 Auxiliary Space is the extra space or temporary space used by an algorithm.
 
 Space Complexity of an algorithm is total space taken by the algorithm with respect to the input size. Space complexity includes both Auxiliary space and space used by input.
 
 For example, if we want to compare standard sorting algorithms on the basis of space, then Auxiliary Space would be a better criteria than Space Complexity. Merge Sort uses O(n) auxiliary space, Insertion sort and Heap Sort use O(1) auxiliary space. Space complexity of all these sorting algorithms is O(n) though.

Space Complexity of Merge Sort is O(n)*/

void printArray(int a[], int size);

void merge(int left[], int right[], int sizeLeft, int sizeRight, int finalArr[]) {
    
    int i = 0, j = 0, k = 0;
    
    while (i < sizeLeft && j < sizeRight) {
        if (left[i] < right[j]) {
            finalArr[k] = left[i];
            i ++;
            k ++;
        }
        else {
            finalArr[k] = right[j];
            j ++;
            k ++;
        }
    }
    while (i < sizeLeft) {
        finalArr[k] = left[i];
        i ++;
        k ++;
    }
    while (j < sizeRight) {
        finalArr[k] = right[j];
        j ++;
        k ++;
    }
    printf("@@@@@@@@@@@@@FINAL SORTED ARRAY IS@@@@@@@@@@@@@@@@@@@\n");
    printArray(finalArr, k);
}

void mergeSort(int a[], int n) {
    
    if (n < 2) {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for (int i = 0; i < mid; i ++) {
        left[i] = a[i];
    }
    for (int i = mid; i < n; i ++) {
        right[i - mid] = a[i];
    }
    mergeSort(left, mid);
    printf("++++++++++++LEFT ARRAY+++++++++++++");
    printArray(left, mid);
    mergeSort(right, n - mid);
    printf("++++++++++++RIGHT ARRAY+++++++++++++");
    printArray(right, n - mid);
    merge(left, right, mid, n - mid, a);
}

void printArray(int a[], int size) {
    
    for (int i = 0; i < size; i ++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    int a[] = {34,12,32,21,3,67,15,4};
    int arr_size = sizeof(a)/sizeof(a[0]);
    
    printArray(a, arr_size);
    
    mergeSort(a, arr_size);
    
    return 0;
}

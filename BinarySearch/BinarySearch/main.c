//
//  main.c
//  BinarySearch
//
//  Created by Arun Kumar on 05/01/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>

int normalBinarySearch(int a[], int size, int searchElement) {
    
    int l = 0, r = size - 1;
    int mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (searchElement == a[mid]) {
            return mid;
        }
        else if (searchElement < a[mid]) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return -1;
}

int recursiveBinarySearch(int a[], int left, int right, int searchElement) {
    
    printf("LEFT : %d & RIGHT : %d \n",left,right);
    int mid = (left + right) / 2;
    
    printf("MID is : %d \n",mid);
    if (searchElement == a[mid]) {
        return mid;
    }

    if (left <= right) {
        if (searchElement < a[mid]) {
            return recursiveBinarySearch(a, left, mid - 1, searchElement);
        }
        else
            return recursiveBinarySearch(a, mid + 1, right, searchElement);
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,2,3,4,6,7,8};
    int arr_size = sizeof(a)/sizeof(a[0]);
    
    printf("Normal Search Index is : %d \n",normalBinarySearch(a,arr_size,0));
    printf("Recursive Search Index is : %d \n",recursiveBinarySearch(a, 0, arr_size, 0));
    return 0;
}

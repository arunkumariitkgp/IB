//
//  main.c
//  BitsTwoPointers
//
//  Created by Arun Kumar on 04/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//Number of 1 bits
int numSetBits(unsigned int A) {
    int count = 0;
    while(A) {
        A &= (A-1);
        count ++;
    }
    return count;
}

/*
 XOR will returns 1, only on two different bits. So if two numbers are the same, XOR will return 0.
 
 Finally, there is only one number left.
 
 A ^ A = 0 and A ^ B ^ A = B.
 
 So, all even occurences will cancel out using XOR.
 */
int singleNumber1(int *A, int n) {
    
    int count = 0, i = 0;
    while (i < n) {
        count = count ^ A[i];
        i ++;
    }
    return count;
}

/*
 Find the intersection of two sorted arrays.
 OR in other words,
 Given 2 sorted arrays, find all the elements which occur in both the arrays.
 
 Example :
 
 Input :
 A : [1 2 3 3 4 5 6]
 B : [3 3 5]
 
 Output : [3 3 5]
 
 Input :
 A : [1 2 3 3 4 5 6]
 B : [3 5]
 
 Output : [3 5]
 
 Algorithm Intersection(arr1[], arr2[]):
 For Intersection of two arrays, print the element only if the element is present in both arrays.
 1) Use two index variables i and j, initial values i = 0, j = 0
 2) If arr1[i] is smaller than arr2[j] then increment i.
 3) If arr1[i] is greater than arr2[j] then increment j.
 4) If both are same then print any of them and increment both i and j.
 */
//WE CAN ALSO DO BINARYSEARCH WITH ALL THE ELEMENTS OF ONE ARRAY TO OTHER BUT IT TAKES O(nlogn) time
int* intersect(const int* A, int n1, const int* B, int n2, int *len1) {
    
    int *res = (int *)malloc((n1 + n2) * sizeof(int));
    
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if(A[i] < B[j])
            i++;
        else if(A[i] > B[j])
            j ++;
        else {
            res[k ++] = B[j];
            i ++;
            j ++;
        }
        *len1 = k;
    }
    return res;
}

/*Algorithm Union(arr1[], arr2[]):
For union of two arrays, follow the following merge procedure.
1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i.
3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j.
4) If both are same then print any of them and increment both i and j.
5) Print remaining elements of the larger array.


Function prints union of arr1[] and arr2[]
 m is the number of elements in arr1[]
 n is the number of elements in arr2[] */
void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
        {
        if (arr1[i] < arr2[j])
            printf(" %d ", arr1[i++]);
        else if (arr2[j] < arr1[i])
            printf(" %d ", arr2[j++]);
        else
            {
            printf(" %d ", arr2[j++]);
            i++;
            }
        }
    
    /* Print remaining elements of the larger array */
    while(i < m)
        printf(" %d ", arr1[i++]);
    while(j < n)
        printf(" %d ", arr2[j++]);
}

/*
 Given an array with n objects colored red, white or blue,
 sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note: Using library sort function is not allowed.
 
 Example :
 
 Input : [0 1 2 0 1 2]
 Modify array so that it becomes : [0 0 1 1 2 2]
 
 THIS IS ALSO CALLED — Dutch National Flag Algorithm, or 3-way Partitioning —
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* A, int n1) {
    int low = 0, mid = 0, high = n1-1;
    while(mid<=high) {
        switch(A[mid]){
            case 0: swap(&A[low++],&A[mid++]);
                break;
            case 1: mid ++;
                break;
            case 2: swap(&A[mid],&A[high--]);
                break;
        }
    }
}

/*
 Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 
 Example: Input :
 A : [1 3 5]
 k : 4
 Output : YES as 5 - 1 = 4
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 
 Try doing this in less than linear space complexity.
 */
int diffPossible(int* A, int n1, int B) {
    int i,j;
    for(i = 0; i < n1; i ++)
        for(j = n1-1; j > i; j --) {
            if(A[j]-A[i] == B && i != j)
                return 1;
            if(A[j] - A[i] < B) break;
        }
    
    return 0;
}

/*
 You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
 
 Find i, j, k such that :
 max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
 Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))
 
 **abs(x) is absolute value of x and is implemented in the following manner : **
 
 if (x < 0) return -x;
 else return x;
 Example :
 
 Input :
 A : [1, 4, 10]
 B : [2, 15, 20]
 C : [10, 12]
 
 Output : 5
 With 10 from A, 15 from B and 10 from C.
 */


int main(int argc, const char * argv[]) {
    
    int A[] = {1,2,2,3,3,8,1};
    printf("Count : %d\n",singleNumber1(A, sizeof(A)/sizeof(A[0])));
    return 0;
}

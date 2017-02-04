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

int Sqrt(int A) {
    if (A==1)
        return 1;
    long long low = 0;
    long long high = A;
    while(high - low > 1) {
        long long mid = (low + high) / 2;
        if(mid*mid <= A)
            low = mid;
        else
            high = mid;
    }
    return (int)low;
}

/*
 Given a sorted array of integers, find the number of occurrences of a given target value.
 Your algorithm’s runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return 0
 
 **Example : **
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return 2.
 */
int binarySearch(int *A, int n1, int B, int first) {
    int start = 0;
    int end = n1 - 1;
    int result = -1;
    while(start <= end) {
        int mid = (start + end)/2;
        if(A[mid] == B) {
            result = mid;
            if(first == 1)
                end = mid -1;
            else
                start = mid + 1;
        }
        else if(A[mid] > B)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return result;
}

int findCount(int* A, int n1, int B) {
    int first = binarySearch(A,n1,B,1);
    if(first == -1)
        return 0;
    int last = binarySearch(A,n1,B,0);
    return last - first + 1;
}

//Find the minimum element in a sorted and rotated array:::return A[index]
//OR Finding rotation count:::: return index;
//We use binarySearch with pivot as Next = (Mid+1)%N & Prev = (Mid+N-1)%N

/*
 Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 The array will not contain duplicates.
 
 NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
 PROBLEM APPROACH:
 
 Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].
 Lets look at how we can calculate the number of times the array is rotated.
 */
int findRotationCount(int *A, int n1) {
    
    int low = 0, high = n1 - 1;
    
    while (low <= high) {
        if (A[low] <= A[high]) {
            return low;
        }
        int mid = (low + high) / 2;
        int next = (mid + 1) % n1;
        int prev = (mid + n1 - 1) % n1;
        if (A[mid] <= A[next] && A[mid] <= A[prev]) {
            return mid;
        }
        if (A[mid] <= A[high]) {
            high = mid - 1;
        }
        if (A[mid] >= A[low]) {
            low = mid + 1;
        }
    }
    return -1;
}
/*
 Implement pow(x, n) % d.
 
 In other words, given x, n and d,
 
 find (x^n % d)
 
 Note that remainders on division cannot be negative.
 In other words, make sure the answer you return is non negative.
 
 Input : x = 2, n = 3, d = 3
 Output : 2
 
 2^3 % 3 = 8 % 3 = 2.
 */
long powerFunction(int x, int n, int d) {
    
    long ans=1;
    long square=x;
    if(n==0)
        return 1;
    while(n!=0)
    {
        if(n%2)
            ans=ans*square;
        square=(square*square)%d;
        n=n/2;
        if(ans>d)
            ans=ans%d;
    }
    if(ans < 0)
        ans = d + ans;
    return ans;
}

//This is to calculate x^y
long long power(int x, unsigned int y)
{
    long long temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Here are few examples.
 
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */
int sortedInsertedPosition(int *A, int n, int x) {
    int start = 0, end = n - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == x) {
            return mid;
        }
        if (x < A[mid]) {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return start;
}

/*
 Write an efficient algorithm that searches for a value in an m x n matrix.
 
 This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than or equal to the last integer of the previous row.
 Example:
 
 Consider the following matrix:
 
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 Given target = 3, return 1 ( 1 corresponds to true )
 
 Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
 */
int searchMatrix(int** A, int n11, int n12, int B) {
    int i, start, end, mid;
    for(i = 0; i < n11; i ++) {
        start = 0, end = n12-1;
        while(start <= end) {
            mid = (start+end)/2;
            if(B == A[i][mid])
                return 1;
            if(B < A[i][mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return 0;
}

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
 
 You are given a target value to search. If found in the array, return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 
 Input : [4 5 6 7 0 1 2] and target = 4
 Output : 0
 
 NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
 */
int searchSortedRotatedArray(int *A, int n1, int x) {
    int start = 0, end = n1-1;
    int mid;
    while (start <= end) {
        mid = (start+end)/2;
        if (x == A[mid])
            return mid;
        if (A[start] <= A[mid]) {
            if (x >= A[start] && x < A[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else {
            if (x > A[mid] && x <= A[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
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

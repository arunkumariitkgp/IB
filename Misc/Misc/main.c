//
//  main.c
//  Misc
//
//  Created by Arun Kumar on 09/01/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

//https://www.hackerrank.com/challenges/array-left-rotation
void printLeftAndRightShift() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //    int a[1000000];
    int a[100];
    int n, d;
    scanf("%d%d",&n, &d);
    for(int i = 0; i < n; i ++)
        scanf("%d",&a[i]);
    
    printf("______________________________\n");
    for (int i = 0; i < n; i ++) {
        printf("%d ", a[(i + d) % n]);
    }
    printf("\n");
    for (int i = 0; i < n; i ++) {
        printf("%d ", a[(i + (n - d)) % n]);
    }
    printf("\n");
    printf("______________________________\n");

    for (int i = d; i < n; i ++) {
        printf("%d ",a[i]);
    }
    for (int i = 0; i < d; i ++) {
        printf("%d ",a[i]);
    }

    printf("\n");
    for (int i = n - d; i < n; i ++) {
        printf("%d ",a[i]);
    }
    for (int i = 0; i < n - d; i ++) {
        printf("%d ",a[i]);
    }
}

//https://www.hackerrank.com/challenges/sparse-arrays
void stringQuery() {
    int n;
    scanf("%d",&n);
    char string[n][20];
    for(int i = 0; i < n; i ++)
        scanf("%s",string[i]);
    int q;
    scanf("%d",&q);
    char query[q][20];
    for(int i = 0; i < q; i ++)
        scanf("%s",query[i]);
    
    for(int i = 0; i < q; i ++) {
        int count = 0;
        for(int j = 0; j < n; j ++) {
            if(strcmp(query[i],string[j]) == 0)
                count ++;
        }
        printf("%d\n",count);
    }
}

void printArray(int *A, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%d ",A[i]);
    }
}

//geeksforfeeks "Equal point sorted array"
void equalPointSortedArray() {
    
    int a[] = {1,2,3,3,3,3,4,5};
    int n = 8;
    int b[n], k;
    
    b[0] = a[0];
    k = 1;
    
    for (int i = 1; i < n; i ++) {
        if (a[i] != a[i - 1]) {
            b[k] = a[i];
            k ++;
        }
    }
    if (k%2==0) {
        printf("-1\n");
        return;
    }
    else {
        int element = b[k/2];
        for (int i = 0; i < n; i ++) {
            if (a[i] == element) {
                printf("%d\n",i);
                return;
            }
        }
    }
}

void worstLogicPrime() {
    
    long n;
    scanf("%ld",&n);
    int i = 2;
    while (i < n) {
        if (n%i == 0) {
            printf("Worst NOT a PRIME\n");
            return;
        }
        i ++;
    }
    printf("Worst PRIME\n");
}

int bestLogicPrime(int n) {
    
    int i = 2;
    while (i <= sqrt(n)) {
        if (n%i == 0) {
            return 0;
        }
        i ++;
    }
    return 1;
}

int* plusOne(int* A, int n1, int *length_of_array) {
    
    int *result = (int *)malloc(n1 + 1 * sizeof(int));
    int carry = 1;
    
    for (int i = n1-1; i >= 0; i --) {
        if (carry && A[i] == 9) {
            result[i] = 0;
            carry = 1;
        }
        else {
            result[i] = A[i] + carry;
            carry = 0;
        }
    }
    if (carry) {
        for (int i = n1 - 1; i > 0; i --) {
            result[i + 1] = result[i];
        }
        result[0] = 1;
        n1 ++;
    }
    *length_of_array = n1;

    return result;
}

int* allFactors(int A, int *length_of_array) {
    // SAMPLE CODE
    
    *length_of_array = 1000; // length of result array
    int *result = (int *) malloc(*length_of_array * sizeof(int));
    int i = 1, index = 0;
//    result[0] = 1;
    while(i <= sqrt(A)) {
        if(A%i == 0) {
            result[index] = i;
            index ++;
//            if (i != (A / i)) {
//                result[index] = A/i;
//                index ++;
//            }
        }
        i ++;
    }
    int x = index;
    for (int j = x - 1; j > 0; j --) {
        if ((A%j == 0) && j != A/j) {
            result[x] = A/j;
            x ++;
        }
    }
    *length_of_array = x;
    return result;
}

int* primesum(int A, int *len1) {
    
    int *final = (int *)malloc(2 * sizeof(int));
    for (int i = 2; i < A/2; i ++) {
        if (bestLogicPrime(i)) {
            if (bestLogicPrime(A-i)) {
                final[0] = i;
                final[1] = A-i;
                *len1 = 2;
                printf("%d %d\n",i, A-i);
                return final;
            }
        }
    }
    *len1 = 0;
    return final;
}

int gcd(int A, int B)
{
    //LOGIC 1
    if (B==0)
        return A;
    else
        return gcd (B, A%B);
    
    //LOGIC 2
//    if (A==0)
//        return B;
//    else
//        return (B%A,A);
}

//Polindrome without extra space
int polindrome(int A) {
    
    if (A < 0)
        return 0;
    if (A < 10)
        return 1;
        
    int div = 1;
    while (A/div >= 10) {
        div *= 10;
    }
    
    int l,r;
    while (A) {
        l = A/div;
        r = A%10;
        if (l!=r) {
            return 0;
        }
        A = (A % div) / 10;
        div /= 100;
    }
    return 1;
}

long getExcelColumnNumber(char *ch) {
    
    long count = 0;
    int lenght = (int)strlen(ch);
    int cc, index = 1;
    
    for (int i = lenght - 1; i >=0; i --) {
        cc = (int)ch[i];
        int val = (cc % 65) + 1;
        count = count + val * index;
        index *= 26;
    }
    return count;
}

char* getExcelColumnTitle(long n) {
    
    char *finalChar = (char *)malloc(100 * sizeof(char));
    int rem, index = 0;
    
    while (n > 0) {
        rem = n % 26;
        if (rem == 0) {
            finalChar[index ++] = 'Z';
            n = (n / 26) - 1;
        }
        else {
            finalChar[index ++] = (rem - 1) + 'A';
            n = n / 26;
        }
    }
    
    int last = index;
    char temp;
    for (int i = 0; i < index/2; i ++) {
        temp = finalChar[i];
        finalChar[i] = finalChar[last - 1];
        finalChar[last - 1] = temp;
        last --;
    }
    return finalChar;
}

//Max Sum Contiguous Subarray
#define max(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })
int maxSubArray(int* A, int n1)
{
    int m1=A[0];
    int m2=A[0];
    int i;
    for(i=1;i<n1;i++)
    {
        m2=max(A[i],m2+A[i]);
        m1=max(m2,m1);
    }
    
    return m1;
}

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct interval {
    int start;
    int end;
};

struct interval* mergeIntervals(struct interval *ints, struct interval mInt, int n1, int *length_final) {
    
    struct interval *final = malloc((n1+1)*sizeof(struct interval));
    int index = 0;
    
    for (int i = 0; i < n1; i ++) {
        if (ints[i].end < mInt.start) {
            final[index].start = ints[i].start;
            final[index].end = ints[i].end;
            index ++;
        }
        else if (ints[i].start > mInt.end) {
            final[index].start = mInt.start;
            final[index].end = mInt.end;
            index ++;

            mInt.start = ints[i].start;
            mInt.end = ints[i].end;
        }
        else if(ints[i].end >= mInt.start || ints[i].start <= mInt.end) {
            mInt.start = MIN(ints[i].start,mInt.start);
            mInt.end = MAX(ints[i].end,mInt.end);
        }
    }
    final[index].start = mInt.start;
    final[index].end = mInt.end;
    *length_final = index + 1;
    return final;
}

struct interval* mergeOverlappingIntervals(struct interval *ints, int n1, int *length_final) {
    
    struct interval *final = malloc((n1)*sizeof(struct interval));
    int index = 0;
    
    struct interval prev = ints[0];
    for (int i = 1; i < n1; i ++) {
        if (prev.end < ints[i].start) {
            final[index].start = prev.start;
            final[index].end = prev.end;
            index ++;
            prev.start = ints[i].start;
            prev.end = ints[i].end;
        }
        else if(prev.start > ints[i].end) {
            final[index].start = ints[i].start;
            final[index].end = ints[i].end;
            
            index ++;
            prev.start = ints[i].start;
            prev.end = ints[i].end;
        }
        else if (prev.end >= ints[i].start || prev.start <= ints[i].end) {
            prev.start = MIN(prev.start, ints[i].start);
            prev.end = MAX(prev.end, ints[i].end);
        }
    }
    final[index].start = prev.start;
    final[index].end = prev.end;
    *length_final = index + 1;
    return final;
}

void printMatrix(int row, int column, int a[row][column]) {
    
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < column; j ++) {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//TIME O(M*N) SPACE O(M+N)
void setMatrixZeros(int A[][3], int rows, int columns) {
    
    int row[rows];
    int column[columns];
    
    for (int i = 0; i < rows; i ++) {
        row[i] = 0;
    }
    for (int i = 0; i < columns; i ++) {
        column[i] = 0;
    }
    
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            if (A[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            if (row[i] == 1 || column[j] == 1) {
                A[i][j] = 0;
            }
        }
    }
    printMatrix(A, rows, columns);
}

void setMatrixZerosEfficientWay(int A[][2], int rows, int columns) {
    
    int rFlag = rows;
    int cFlag = columns;
    
    for (int i = 0; i < rows; i ++) {
        if (A[i][0] == 0) {
            rFlag = 0;
            break;
        }
    }
    for (int j = 0; j < columns; j ++) {
        if (A[0][j] == 0) {
            cFlag = 0;
            break;
        }
    }
    for (int i = 1; i < rows; i ++) {
        for (int j = 1; j < columns; j ++) {
            if (A[i][j] == 0) {
                A[0][j] = 99;
                A[i][0] = 99;
            }
        }
    }
    printMatrix(A, rows, columns);
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            if (A[0][j] == 99 || A[i][0] == 99) {
                printf("Entered %d %d\n",i,j);
                A[i][j] = 0;
            }
//            else if (A[0][j] == 0 || A[i][0] == 0) {
//                printf("++Entered %d %d\n",i,j);
//                printf("Value of A[%d][%d]: %d\n",i,j,A[i][j]);
//                A[i][j] = 0;
//                printMatrix(A, rows, columns);
//            }
        }
    }
    for (int i = 1; i < rows; i ++) {
        if (A[i][0] == 0) {
            for (int j = 1; j < columns; j ++) {
                A[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < columns; j ++) {
        if (A[0][j] == 0) {
            for (int i = 1; i < rows; i ++) {
                A[i][j] = 0;
            }
        }
    }

    printMatrix(A, rows, columns);
    if (rFlag == 0) {
        for (int i = 0; i < rows; i ++) {
            A[i][0] = 0;
        }
    }
    if (cFlag == 0) {
        for (int j = 0; j < columns; j ++) {
            A[0][j] = 0;
        }
    }
    printMatrix(A, rows, columns);
}

int squareRoot(int n) {
    
    if (n == 1) {
        return 1;
    }
    long low = 0;
    long high = n;
    
    while (high - low > 1) {
        long mid = (low + high) /2;
        if (mid*mid <= n) {
            low = mid;
        }
        else high = mid;
    }
    return (int)low;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int start, int end) {
    int pivot = A[end];
    int index = start;
    for (int i = index; i < end; i ++) {
        if(A[i] < pivot) {
            swap(&A[i], &A[index]);
            index ++;
        }
    }
    swap(&A[index], &A[end]);
    return index;
}

void quickSort(int *A, int start, int end) {
    if (start < end) {
        int index = partition(A, start, end);
        quickSort(A, start, index - 1);
        quickSort(A, index + 1, end);
    }
}

//Idea is to sort the array and swap adjacent elements but it takes O(nlogn) time. There are several different answers to given input.
//We can also do this in O(n) time.
void waveArray(int *A, int n) {
    
    int start = 0;
    int end = n-1;
    quickSort(A, start, end);
    for (int i = 0; i < n - 1; i += 2) {
        swap(&A[i], &A[i+1]);
    }
}

//O(n) time solution
//http://www.geeksforgeeks.org/sort-array-wave-form-2/
void waveArrayLinearTime(int *A, int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && A[i-1] > A[i])
            swap(&A[i], &A[i-1]);
    
        // If current even element is smaller than next
        if (i<n-1 && A[i] < A[i+1] )
            swap(&A[i], &A[i + 1]);
    }
}

/*
 Find the repeating and the missing numbers.
 Given an unsorted array of size n. Array elements are in range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in array. Find these two numbers.
 
 Examples:
 
 arr[] = {3, 1, 3}
 Output: 2, 3   // 2 is missing and 3 occurs twice
 
 arr[] = {4, 3, 6, 2, 1, 1}
 Output: 1, 5  // 5 is missing and 1 occurs twice
*/
//http://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

//O(n) time and space complexity
void findRepeatingANDMissing(int *A, int n) {
    
    int *temp = (int *)malloc(n * sizeof(int));
    int *res = (int *)malloc(2 * sizeof(int));
    
    for (int i = 1; i <= n; i ++) {
        temp[i] = 0;
    }
    
    for (int i = 0; i < n; i ++) {
        if (temp[A[i]] == 0) {
            temp[A[i]] = 1;
        }
        else {
//            printf("Repeated one : %d \n",A[i]);
            res[0] = A[i];
        }
    }
    printf("%d \n",res[0]);

    for (int i = 1; i <= n; i ++) {
        if (temp[i] == 0) {
//            printf("Missing one : %d \n",i);
            res[1] = i;
        }
    }
    printf("%d \n",res[1]);
}

//O(n) time and O(1) space
void findRepeatingANDMissingEfficient(int *A, int n) {
    
    for (int i = 0; i < n; i ++) {
        if (A[abs(A[i]) - 1] > 0) {
            A[abs(A[i]) - 1] = - A[abs(A[i])-1];
        }
        else {
            printf("Repeated one : %d \n",abs(A[i]));
        }
    }
//    printArray(A,n);
    for (int i = 0; i < n; i ++) {
        if (A[i] > 0) {
            printf("Missing one : %d \n",i+1);
        }
    }
}

void findRepeatingANDMissingEquation(int *A, int n) {
    
    long sumActual = 0,sum1n;
    long sumSqAct = 0, sumSq1n;
    int X, Y;
    
    sum1n = (n*(n+1))/2;
    sumSq1n = (n*(n+1)*(2*n+1))/6;
    for (int i = 0; i < n; i ++) {
        sumActual += A[i];
        sumSqAct += A[i]*A[i];
    }
    
    X = (int)((sumSqAct - sumSq1n)/(sumActual - sum1n) + (sumActual - sum1n)) / 2;
    Y = (int)(X - (sumActual - sum1n));
    printf("%d, %d",X,Y);
}


int segrigate(int *A, int n1) {
    int i,j=0;
    for(i = 0; i < n1; i ++) {
        if(A[i] <= 0) {
            swap(&A[i],&A[j]);
            j++;
        }
    }
    return j;
}
/*
 Given an unsorted integer array, find the first missing positive integer.
 
 Example:
 
 Given [1,2,0] return 3,
 
 [3,4,-1,1] return 2,
 
 [-8, -7, -6] returns 1
 
 Your algorithm should run in O(n) time and use constant space.
*/
int firstMissingPositive(int* A, int n1) {
    int i;
    int j = segrigate(A, n1);
    n1 = n1 - j;
    A = A + j;
    for(i = 0; i < n1; i ++) {
        if(abs(A[i]) - 1 < n1 && A[abs(A[i]) - 1] > 0) {
            A[abs(A[i]) - 1] = - A[abs(A[i]) - 1];
        }
    }
    for(i = 0; i < n1; i ++) {
        if(A[i] > 0)
            return i + 1;
    }
    return n1+1;
}

//O(n) space and time
int findDuplicate(int *A, int n1) {
    int *temp = (int *)malloc((n1-1) * sizeof(int));
    
    for (int i = 1; i < n1; i ++) {
        temp[i] = 0;
    }
    
    for (int i = 0; i < n1; i ++) {
        if (temp[A[i]] == 0) {
            temp[A[i]] = 1;
        }
        else
            return A[i];
    }
    return -1;
}

//O(1) space and O(n) time
int findDuplicateEfficient(int *A, int n1) {
    
    for (int i = 0; i < n1; i ++) {
        if (A[abs(A[i])-1] > 0) {
            A[abs(A[i])-1] = - A[abs(A[i])-1];
        }
        else
            return A[i];
    }
    return -1;
}

/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish’ in the diagram below).
 
 How many possible unique paths are there?
 
 Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

 There is a mathematical approach to solving this problem.
 
 Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.
 
 Let 0 denote a down step and 1 denote a right step.
 
 So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.
 
 Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.
 
 So, the answer becomes Choose(m+n-2, n - 1).
 https://www.interviewbit.com/problems/grid-unique-paths/
*/

int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)!
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}
//EASY WAY
int uniquePathsEasy(int m, int n) {
    
    if (m == 1 || n == 1)
        return 1;
    return uniquePaths(m-1, n)+uniquePaths(m, n-1);
}

/*
 Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
 
 Example:
 
 Input : [1, 0]
 Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
 * All elements in the array are in the range [0, N-1]
 * N * N does not overflow for a signed integer
 */
int *rearrange(int *A, int n1) {
    
    return A;
}

/*
 Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
 
 Example
 
 Input : 4
 Output : True
 as 2^2 = 4.
 https://www.interviewbit.com/problems/power-of-two-integers/
 */
int isPower(int A) {
    if(A==1)
        return 1;
    int i,p;
    p = (int)sqrt(A);
    if(p*p == A)//IF perfect square the return 1;
        return 1;
    if(A%2 == 0)//***IF A is even then it can't be the power of ODD and vice versa. So we can check only EVEN/ODD values if num is EVEN/ODD
        i = 2;
    else i = 3;
    for(;i <= sqrt(A); i += 2) {
        p = i;
        while(p <= A) {
            if(p == A)
                return 1;
            p = p*i;
        }
    }
    return 0;
}

/*
 Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
 https://www.interviewbit.com/problems/rearrange-array/
 Example:
 
 Input : [1, 0]
 Return : [0, 1]
 
 SOLUTION:
 1) Increase every array element arr[i] by (arr[arr[i]] % n)*n.
 2) Divide every element by n.
 
 Let us understand the above steps by an example array {3, 2, 0, 1}
 In first step, every value is incremented by (arr[arr[i]] % n)*n
 After first step array becomes {7, 2, 12, 9}.
 The important thing is, after the increment operation
 of first step, every element holds both old values and new values.
 Old value can be obtained by arr[i]%n and new value can be obtained
 by arr[i]/n.
 
 In second step, all elements are updated to new or output values
 by doing arr[i] = arr[i]/n.
 After second step, array becomes {1, 0, 3, 2}
 */
void arrange(int* A, int n1) {
    int i;
    for(i = 0; i < n1; i ++)
        A[i] += (A[A[i]]%n1)*n1;
    for(i = 0; i < n1; i ++)
        A[i] /= n1;
}

//Trailing Zeros in Factorial
//http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
int trailingZeroesInFactorial(int A) {
    int i,count = 0;
    for(i = 5; A/i >= 1; i *= 5) {
        count += A/i;
    }
    return count;
}

/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example:
 
 Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */
int digits(int n) {
    int prod = 1;
    while (n) {
        n /= 10;
        prod *= 10;
    }
    return prod;
}

int largestPartition(int *A, int start, int end) {
    
    int pivot = A[end];
    int index = start;
    for (int i = index; i < end; i ++) {
        int xy = A[i] * digits(pivot) + pivot;
        int yx = pivot * digits(A[i]) + A[i];
        if (xy > yx) {
            swap(&A[i], &A[index]);
            index ++;
        }
    }
    swap(&A[index], &A[end]);
//    printArray(A, end + 1);
    return index;
}

void largestQuickSort(int *A, int start, int end) {
    if (start < end) {
        int index = largestPartition(A, start, end);
        largestQuickSort(A, start, index - 1);
        largestQuickSort(A, index + 1, end);
    }
}

//WRONG CODING. NEED TO MAKE CHAR ARRAY FROM INT ARRAY.
char* largestNumFromArray(int *A, int n) {
    
    largestQuickSort(A, 0, n - 1);
    printArray(A, n);
    char *final = (char *)malloc(100 * sizeof(char));
    int i,index = 0;
    int div,num;
    for (i = 0; i < n; i ++) {
        div = 1; num = A[i];
        while (num/div >= 10) {
            div *= 10;
            num /= 10;
        }
        
        num = A[i];
        while (num) {
            final[index] = (num / div) + '0';
            num = num % div;
            div /= 10;
            index ++;
        }
    }
    final[i] = '\0';
    return final;
}

void rotateMatrixAntiClockWise(int size,int A[][size]) {
    
    for (int i = 0; i <= size/2; i ++) {
        for (int j = i; j < size - 1 - i; j ++) {
            int temp = A[i][j];
            A[i][j] = A[j][size - 1 - i];
            A[j][size - 1 - i] = A[size - 1 - i][size - 1 - j];
            A[size - 1 - i][size - 1 - j] = A[size - 1 - j][i];
            A[size - 1 - j][i] = temp;
        }
    }
}

void rotateMatrixClockWise(int row, int column ,int A[][column]) {
    
    int size = row;
    for (int i = 0; i <= size/2; i ++) {
        for (int j = i; j < size - 1 - i; j ++) {
            int temp = A[i][j];
            A[i][j] = A[size - 1 - j][i];
            A[size - 1 - j][i] = A[size - 1 - i][size - 1 - j];
            A[size - 1 - i][size - 1 - j] = A[j][size - 1 - i];
            A[j][size - 1 - i] = temp;
        }
    }
}

int **pascalTriangle(int A, int *number_of_rows) {

    *number_of_rows = A;
    int **result = (int **)malloc(A * sizeof(int *));
    int i,j;
    for(i = 0; i < A; i ++) {
        result[i] = (int *)malloc((i+2)*sizeof(int));
        result[i][0] = i + 1;
    }
    
    for(i = 0; i < A; i ++){
        for(j = 0; j <= i; j ++){
            if(i == j || j == 0)
                result[i][j+1] = 1;
            else
                result[i][j+1] = result[i-1][j]+result[i-1][j+1];
        }
    }
    return result;
}

//C(n,k+1) = C(n,k) * (n-k) / (k+1)
void kthRowPascalTriangle(int k) {
    
    int *res = (int *)malloc((k+1)*sizeof(int));
    int x = 1;
    for (int i = 0; i <= k; i ++) {
        res[i] = x;
        x = x * (k-i)/(i+1);
    }
    printArray(res, k + 1);
}

void spiralPrint(int n) {
    
    int **A = (int **)malloc((n*n)*sizeof(int));
    
    for (int i = 0; i < n; i ++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    
    int sr = 0, sc = 0, er = n-1, ec = n-1;
    int dir = 0,k = 1;
    while (sr <= er && sc <= ec) {
        if (dir == 0) {
            for (int i = sc; i <= ec; i ++) {
                A[sr][i] = k ++;
            }
            sr ++;
        }
        else if (dir == 1) {
            for (int i = sr; i <= er; i ++) {
                A[i][ec] = k ++;
            }
            ec --;
        }
        else if (dir == 2) {
            for (int i = ec; i >= sc; i --) {
                A[er][i] = k ++;
            }
            er --;
        }
        else if(dir == 3) {
            for (int i = er; i >= sr; i --) {
                A[i][sc] = k ++;
            }
            sc ++;
        }
        dir = (dir + 1) % 4;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {

//    char ch[] = "baaaabbaaabbaabbaaaaaabaaaaaaabbbbaaaabbaabbababbbaaaabababaabaabaabaabbabbabbbabbbaaabaaaabaaaaaab";
//    char sear[] = "aabbbababbbaabaaabbaaabbbbbabababaabaaabbbbaaaaaa";
//    char ch[] = "bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba";
//    char sear[] = "babaaa";
    char ch[] = "aabaaaababaabbbabbabbbaabababaaaaaababaaabbabbabbabbaaaabbbbbbaabbabbbbbabababbaaabbaabbbababbb";
    char sear[] = "bba";
    printf("STR STR : %d\n",strStr(ch, sear));
    return 0;
}

//
//  main.c
//  Arrays
//
//  Created by Arun Kumar on 04/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>

void printArray(int *A, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%d ",A[i]);
    }
}

int* plusOne(int* A, int n1, int *length_of_array) {
    
    int *result = (int *)malloc((n1 + 1) * sizeof(int));
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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

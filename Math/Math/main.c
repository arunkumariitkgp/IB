//
//  main.c
//  Math
//
//  Created by Arun Kumar on 04/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void printArray(int *A, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%d ",A[i]);
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


//Trailing Zeros in Factorial
//http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
int trailingZeroesInFactorial(int A) {
    int i,count = 0;
    for(i = 5; A/i >= 1; i *= 5) {
        count += A/i;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

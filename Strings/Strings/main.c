//
//  main.c
//  Strings
//
//  Created by Arun Kumar on 04/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int value(char ch) {
    if(ch == 'I')
        return 1;
    if(ch == 'V')
        return 5;
    if(ch == 'X')
        return 10;
    if(ch == 'L')
        return 50;
    if(ch == 'C')
        return 100;
    if(ch == 'D')
        return 500;
    if(ch == 'M')
        return 1000;
    return 0;
}

int romanToInt(char* A) {
    int i = 0, sum = 0;
    
    while(A[i]!='\0') {
        int j = i;
        while(A[j+1]!='\0' && value(A[j]) < value (A[j+1])) {
            j ++;
        }
        int k = j;
        int sum1 = value(A[j]);
        j --;
        while(i <= j){
            sum1 -= value(A[j]);
            j --;
        }
        sum += sum1;
        i = k + 1;
    }
    return sum;
}

void reverse(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin ++;
        end --;
    }
}

void reverseWordByWord(char *A) {
    
    printf("WORD : %s\n",A);
    char *word_begin = NULL;
    char *word_current_position = A;
    
    while (*word_current_position) {
        
        if (word_begin == NULL && *word_current_position != ' ') {
            word_begin = word_current_position;
        }
        if (word_begin && (*(word_current_position + 1) == ' ' || *(word_current_position + 1) == '\0')) {
            reverse(word_begin, word_current_position);
            word_begin = NULL;
        }
        word_current_position ++;
    }
    printf("BEFORE REV: %s\n",A);
    reverse(A, word_current_position - 1);
    printf("FINAL : %s\n",A);
}

char* zigzag(char* A, int B) {
    
    if(B==0 || B==1)
        return A;
    int lenght = (int)strlen(A);
    char **str = (char **)malloc(B * sizeof(char));
    int i;
    for(i = 0; i < B; i ++)
        str[i] = (char *)malloc(100 * sizeof(char));
    
    int down = 1;
    int row = 0;
    int index = 0;
    int reachedHigh = 0;
    for(i = 0; i < lenght; i ++) {
        strncat(str[row], &A[i],1);
        if(row == B-1){
            reachedHigh = 1;
            down = 0;
            index ++;
        }
        if(row == 0 && reachedHigh){
            down = 1;
            index ++;
        }
        if(down)
            row ++;
        else
            row --;
    }
    for (int i = 0; i < B; i ++) {
        printf("STR : %s\n",str[i]);
    }
    char *res = (char *)malloc(lenght * sizeof(char));
    for(i = 0; i < B; i ++)
        strcat(res,str[i]);
    res[lenght] = '\0';
    return res;
}

//KMP Algorithm for pattern matching. Video at https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=1s
void calculateLPS(const char *needle, int lenN, int *lps);
int strStr(const char* haystack, const char* needle) {
    
    int lenN = (int)strlen(needle);
    int lenA = (int)strlen(haystack);
    int *lps = (int *)malloc(lenN * sizeof(int));
    calculateLPS(needle, lenN, lps);
    
    int i = 0, j = 0;
    while(i < lenA) {
        if (haystack[i] == needle[j]) {
            i ++;
            j ++;
        }
        if (j == lenN) {
            printf("Pattern found at index :%d\n",i - j);
            j = lps[j-1];
        }
        else if(i < lenA && haystack[i] != needle[j]){
            if (j != 0)
                j = lps[j - 1];
            else
                i ++;
        }
    }
    return -1;
}

//LPS - Longest prefix suffix
void calculateLPS(const char *needle, int lenN, int *lps) {
    
    int j = 0;
    int i = 1;
    lps[0] = 0;
    while(i < lenN) {
        if(needle[i] == needle[j]) {
            j ++;
            lps[i] = j;
            i ++;
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i ++;
            }
        }
    }
}
//Naive Pattern Searching algorithm
void search(char *pat, char *txt)
{
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);
    
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
        {
        int j;
        
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;
        
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
        }
}

int isNumeric(char ch) {
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

//AtoI https://www.interviewbit.com/problems/atoi/
int matoi(const char* A) {
    
    int sign = 1;
    int i = 0;
    int res = 0;
    while(A[i] == ' ') {
        i ++;
    }
    // printf("I ==== %d\n",i);
    if(A[i] == '-'){
        sign = -1;
        i ++;
    }
    else if(A[i] == '+'){
        sign = 1;
        i ++;
    }
    while(A[i] != '\0' && isNumeric(A[i])) {
        if(res > INT_MAX/10 || (res == INT_MAX/10 && A[i]-'0' > 7)){
            if(sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        res = (res * 10) + (A[i] - '0');
        i ++;
    }
    return sign*res;
}

/*
 Given a string S, find the longest palindromic substring in S.
 
 Substring of string S:
 
 S[i...j] where 0 <= i <= j < len(S)
 
 Palindrome string:
 
 A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
 
 Incase of conflict, return the substring which occurs first ( with the least starting index ).
 
 Example :
 
 Input : "aaaabaaa"
 Output : "aaabaaa"
 http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
 */
//TIME O(n^2) and SPACE O(n^2)
char* longestPalindrome(char* A) {
    int i,j,n;
    n = (int)strlen(A);
    int **table = (int **)malloc((n*n)*sizeof(int*));
    for (int i = 0; i < n; i ++) {
        table[i] = (int *)malloc(n * sizeof(int));
    }
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            table[i][j] = 0;
    int start = 0, maxlen = 1;
    for(i=0;i<n;i++)
        table[i][i] = 1;
    for(i = 0; i < n -1; i ++) {
        if(A[i] == A[i + 1]){
            table[i][i+1] = 1;
            start = i;
            maxlen = 2;
        }
    }
    int k;
    for(k = 3; k < n; k ++){
        for(i = 0; i < n-k+1; i ++){
            j = i + k -1;
            if(table[i+1][j-1] && A[i]==A[j]){
                table[i][j] = 1;
                start = i;
                maxlen = k;
            }
        }
    }
    char *res = (char *)malloc(1000000*sizeof(char));
    for(i = start; i < start+maxlen; i ++)
        res[i - start] = A[i];
    res[i] = '\0';
    return res;
}

//TIME O(n^2) and SPACE O(1);
char* longestPalSubstr(char *A)
{
    int maxLength = 1;  // The result (length of LPS)
    
    int start = 0;
    int len = (int)strlen(A);
    
    int low, high;
    
    // One by one consider every character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && A[low] == A[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        
        // Find the longest odd length palindrome with center
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && A[low] == A[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    
    char *res = (char *)malloc(1000000*sizeof(char));
    int i;
    for(i = start; i < start+maxLength; i ++)
        res[i - start] = A[i];
    res[i] = '\0';
    return res;
}

int main(int argc, const char * argv[]) {

    printf("STR : %s\n",longestPalSubstr("abbcccbbbcaaccbababcbcabca"));
    return 0;
}

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

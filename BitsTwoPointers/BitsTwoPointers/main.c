//
//  main.c
//  BitsTwoPointers
//
//  Created by Arun Kumar on 04/02/17.
//  Copyright © 2017 Pervacio. All rights reserved.
//

#include <stdio.h>

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

int main(int argc, const char * argv[]) {
    
    int A[] = {1,2,2,3,3,8,1};
    printf("Count : %d\n",singleNumber1(A, sizeof(A)/sizeof(A[0])));
    return 0;
}

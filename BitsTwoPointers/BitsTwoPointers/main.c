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

int main(int argc, const char * argv[]) {
    return 0;
}

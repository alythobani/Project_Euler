//
//  main.cpp
//  Euler 14
//
//  Created by Aly Thobani on 16-01-11.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* The following iterative sequence is defined for the set of positive integers:
 
 n → n/2 (n is even)
 n → 3n + 1 (n is odd)
 
 Using the rule above and starting with 13, we generate the following sequence:
 
 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 
 Which starting number, under one million, produces the longest chain?
 
 NOTE: Once the chain starts the terms are allowed to go above one million. */

#include <iostream>

int maxstarter = 1000000;

int chainLength(long n) {
    int counter = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n/2;
        }
        else {
            n = 3*n + 1;
        }
        counter++;
    }
    return counter;
}

int main(int argc, const char * argv[])
{
    int greatestlength = 1;
    int beststarter = 1;
    for (int i = 1; i < maxstarter; i++) {
        int length = chainLength(i);
        if (length > greatestlength) {
            greatestlength = length;
            beststarter = i;
        }
    }
    printf("greatest length is %d, started by %d", greatestlength, beststarter);
    return 0;
}


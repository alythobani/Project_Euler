//
//  main.cpp
//  Euler 3
//
//  Created by Aly Thobani on 16-01-06.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ? */

#include <iostream>

int isPrime(int i) {
    int isprime = 1;
    int x = 3;
    while (x < i) {
        if (i % x == 0) {
            isprime = 0;
            break;
        }
        x = x + 2;
    }
    return isprime;
}

int main(int argc, const char * argv[])
{
    int lp = 1;
    for (int i = 3; i < 600851475143/lp; i = i+2) {
        if (600851475143%i == 0) {
            if (isPrime(i)) {
                lp = i;
            }
        }
    }
    printf("largest prime factor is %d", lp);
    return 0;
}




//
//  main.cpp
//  Euler 10
//
//  Created by Aly Thobani on 16-01-07.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 
 Find the sum of all the primes below two million. */

#include <iostream>

int n = 2000000;

int isPrime(int i) {
    int isprime = 1;
    int x = 3;
    while (x <= i/x) {
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
    long sum = 2;
    for (int i = 3; i < n; i = i + 2) {
        if (isPrime(i)) {
            sum += i;
            printf("found one: %d\n", i);
        }
    }
    printf("sum is %ld", sum);
    return 0;
}


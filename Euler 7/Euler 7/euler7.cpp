//
//  main.cpp
//  Euler 7
//
//  Created by Aly Thobani on 16-01-07.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//
/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 
 What is the 10 001st prime number? */

#include <iostream>
using namespace std;


int isPrime(int i) {
    int isprime = 1;
    int x = 3;
    while (x <= i/x) {
//        printf("Checking if divisible by %d; checking up to %d.\n", x, i/x);
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
    int n;
    cout << "Which prime do you want to know? ";
    cin >> n;
    int a = 2;
    int i = 3;
    while (a < n + 1) {
        if (isPrime(i)) {
            a++;
            printf("The %dth prime is %d!\n", a-1, i);
        }
        i = i + 2;
    }
    //printf("The %dth prime is %d!\n", n, i - 2);
    return 0;
}


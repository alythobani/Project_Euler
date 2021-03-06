//
//  main.cpp
//  Euler 12
//
//  Created by Aly Thobani on 16-01-10.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 
 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 
 Let us list the factors of the first seven triangle numbers:
 
 1: 1
 3: 1,3
 6: 1,2,3,6
 10: 1,2,5,10
 15: 1,3,5,15
 21: 1,3,7,21
 28: 1,2,4,7,14,28
 We can see that 28 is the first triangle number to have over five divisors.
 
 What is the value of the first triangle number to have over five hundred divisors? */

#include <iostream>

int minimumDivisors = 500;

int numberOfDivisors(int n) {
    int number = 2; //already know 1 and n divide n
    for (int i = 2; i < n/i; i++) {
        if (n % i == 0) number = number + 2;
    }
    return number;
}

int main(int argc, const char * argv[])
{
    int n = 1;
    while (1) {
        int triangularNumber = (n*(n+1))/2;
        if (numberOfDivisors(triangularNumber) > minimumDivisors) {
            printf("first triangle number is %d", triangularNumber);
            break;
        }
        n++;
    }
    return 0;
}


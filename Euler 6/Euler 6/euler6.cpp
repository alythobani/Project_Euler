//
//  main.cpp
//  Euler 6
//
//  Created by Aly Thobani on 16-01-07.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* The sum of the squares of the first ten natural numbers is,
 
 12 + 22 + ... + 102 = 385
 The square of the sum of the first ten natural numbers is,
 
 (1 + 2 + ... + 10)2 = 552 = 3025
 Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 
 Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */

#include <iostream>

int sumsquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i*i;
    printf("sum of the squares is %d\n", sum);
    return sum;
}

int squaresum(int n) {
    int sum = n*(n+1)/2;
    sum = sum*sum;
    printf("square of the sum is %d\n", sum);
    return sum;
}

int main(int argc, const char * argv[])
{
    int n = 100;
    
    int difference = abs(sumsquares(n) - squaresum(n));
    printf("difference is %d\n", difference);
    
    return 0;
}


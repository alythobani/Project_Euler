//
//  main.cpp
//  Euler 16
//
//  Created by Aly Thobani on 16-01-13.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
 What is the sum of the digits of the number 2^1000? */

#include <iostream>

int power = 1000;
int numdigits = power - 1;

int main(int argc, const char * argv[])
{
    int number[numdigits];
    number[0] = 2;
    for (int i = 1; i < power - 1; i++) number[i] = 0;
    for (int j = 0; j < power - 1; j++) {
        int indexoffirstzero = 0;
        while (number[indexoffirstzero] != 0) indexoffirstzero++;
        int carryflag = 0;
        for (int i = 0; i < numdigits; i++) {
            if (carryflag) {
                number[i] = 2*(number[i]) + 1;
                carryflag = 0;
            }
            else number[i] *= 2;
            if (number[i] > 9) {
                carryflag = 1;
                number[i] = number[i] % 10;
            }
        }
    }
    int sum = 0;
    for (int i = numdigits-1; i >= 0; i--) {
        int digit = number[i];
        printf("%d", digit);
        sum += digit;
    }
    printf("\nsum is %d\n", sum);
    
    return 0;
}


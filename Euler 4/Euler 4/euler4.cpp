//
//  main.cpp
//  Euler 4
//
//  Created by Aly Thobani on 16-01-06.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers. */

#include <iostream>

int isPalindrome(int x) {
    int rev = 0;
    int temp = x;
    while (temp != 0) {
        int lastdigit = temp % 10;
        rev += lastdigit;
        rev *= 10;
        temp /= 10;
    }
    rev /= 10;
    return (rev == x);
}

int main(int argc, const char * argv[])
{
    int lp = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = 100; b < 1000; b++) {
            int x = a*b;
            if (x > lp && isPalindrome(x)) {
                lp = x;
            }
        }
    }
    printf("largest palindrome is %d", lp);
    return 0;
}


//
//  main.cpp
//  Euler 9
//
//  Created by Aly Thobani on 16-01-07.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 
 a2 + b2 = c2
 For example, 32 + 42 = 9 + 16 = 25 = 52.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 Find the product abc. */

#include <iostream>

int main(int argc, const char * argv[])
{
    for (int a = 1; a < 500; a++) {
        for (int b = a + 1; b < 500; b++) {
            for (int c = b + 1; c < 999; c++) {
                if (a*a + b*b == c*c) {
                    if (a + b + c == 1000) {
                        printf("a = %d, b = %d, c = %d\n", a, b, c);
                        printf("product is %d", a*b*c);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}


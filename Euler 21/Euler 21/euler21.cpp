//
//  main.cpp
//  Euler 21
//
//  Created by Aly Thobani on 16-01-18.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 
 Evaluate the sum of all the amicable numbers under 10000. */

#include <iostream>

int maximum = 10000;

int sumProperDivisorsOdd(int n) {
    int sum = 1;
    for (int x = 3; x <= n/x; x = x+2) {
        if (n % x == 0) sum += x + n/x;
    }
    return sum;
}

int sumProperDivisorsEven(int n) {
    int sum = 1;
    for (int x = 2; x <= n/x; x++) {
        if (n % x == 0) sum += x + n/x;
    }
    return sum;
}

int sumProperDivisors(int n) {
    if (n % 2 == 0) return sumProperDivisorsEven(n);
    else return sumProperDivisorsOdd(n);
}

int main(int argc, const char * argv[])
{
    int sumofamicablenumbers = 0;
    for (int i = 1; i < maximum; i++) {
        int sumofproperdivisors1 = sumProperDivisors(i);
        if (sumofproperdivisors1 > i) {
            int sumofproperdivisors2 = sumProperDivisors(sumofproperdivisors1);
            if (sumofproperdivisors2 == i) {
                sumofamicablenumbers += sumofproperdivisors1 + i;
            }
        }
    }
    printf("sum of amicable numbers under %d is %d\n", maximum, sumofamicablenumbers);
    return 0;
}


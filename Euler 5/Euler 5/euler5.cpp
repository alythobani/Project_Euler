//
//  main.cpp
//  Euler 5
//
//  Created by Aly Thobani on 16-01-06.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 
 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20? */

#include <iostream>

int n = 20;

int main(int argc, const char * argv[])
{
    int lcm = 1;
    
    int count[n+1];
    for (int i = 0; i < n+1; i++) count[i] = 0;
    
    for (int i = 2; i <= n; i++) {
        int temp = i;
        for (int a = 2; a <= temp && temp > 1; a++) {
            int acount = 0;
            while (temp % a == 0) {
                acount++;
                temp /= a;
            }
            if (acount > count[a]) count[a] = acount;
        }
    }
    
    for (int i = 0; i < n+1; i++) printf("%d: %d\n", i, count[i]);
    for (int i = 0; i < n+1; i++) {
        while (count[i] > 0) {
            lcm *= i;
            count[i]--;
        }
    }
    printf("smallest number is %d\n", lcm);
}


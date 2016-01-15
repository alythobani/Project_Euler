//
//  main.cpp
//  Euler 1
//
//  Created by Aly Thobani on 16-01-05.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int sum = 0;
    for (int i = 1; 3*i < 1000; i++) {
        sum += 3*i;
    }
    for (int i = 1; 5*i < 1000; i++) {
        sum += 5*i;
    }
    for (int i = 1; 15*i < 1000; i++) {
        sum -= 15*i;
    }
    printf("sum is %d", sum);
    return 0;
}


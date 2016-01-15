//
//  main.cpp
//  Euler 15
//
//  Created by Aly Thobani on 16-01-11.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner. 
 
 How many such routes are there through a 20×20 grid? */

#include <iostream>

int n = 20;

int main(int argc, const char * argv[])
{
    
    long grid[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
    }
    long totalroutes = grid[n][n];
    printf("%ld", totalroutes);
    return 0;
}


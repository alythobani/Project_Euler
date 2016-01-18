//
//  main.cpp
//  Euler 18
//
//  Created by Aly Thobani on 16-01-14.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 
    3
   7 4
  2 4 6
 8 5 9 3
 
 That is, 3 + 7 + 4 + 9 = 23.
 
 Find the maximum total from top to bottom of the triangle below:
 
               75
              95 64
             17 47 82
            18 35 87 10
           20 04 82 47 65
          19 01 23 75 03 34
         88 02 77 73 07 63 67
        99 65 04 28 06 16 70 92
       41 41 26 56 83 40 80 70 33
      41 48 72 33 47 32 37 16 94 29
     53 71 44 65 25 43 91 52 97 51 14
    70 11 33 28 77 73 17 78 39 68 17 57
   91 71 52 38 17 14 91 43 58 50 27 29 48
  63 66 04 68 89 53 67 30 73 16 69 87 40 31
 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 
 NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o) */

/* 
 75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23 */

#include <iostream>
#include <string>

int numberofrows = 15;
int numberofnumbers = (numberofrows*(numberofrows+1))/2;
int sum = 0;
int iterationcount = 0;

void traverseDownAndSum(int i, int j, int** triangle, int tempsum) {
    iterationcount++;
    int value = triangle[i][j];
    tempsum += value;
    if (i == numberofrows-1) {
        if (tempsum > sum) sum = tempsum;
    }
    else {
        traverseDownAndSum(i+1, j, triangle, tempsum);
        traverseDownAndSum(i+1, j+1, triangle, tempsum);
    }
}

int main(int argc, const char * argv[])
{
    
    std::string trianglestr = " 75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
    
    int** triangle;
    triangle = new int*[numberofrows];
    //initialize all values to 0
    for (int i = 0; i < numberofrows; i++) {
        triangle[i] = new int[numberofrows];
        for (int j = 0; j < numberofrows; j++) {
            triangle[i][j] = 0;
        }
    }
    
    for (int i = 0; i < numberofrows; i++) { //i is rows
        for (int j = 0; j <= i; j++) {
            int position = i*(i+1)/2 + j;
            std::string valuestring = trianglestr.substr(3*position+1, 2);
            int valueint = atoi(valuestring.c_str());
            triangle[i][j] = valueint;
        }
    }
    for (int i = 0; i < numberofrows; i++) {
        for (int x = numberofrows-i-1; x >= 0; x--) {
            printf(" ");
        }
        for (int j = 0; j < numberofrows; j++) {
            int valuetoprint = triangle[i][j];
            if (valuetoprint != 0) {
                if (valuetoprint/10 == 0) printf("0");
                printf("%d ", triangle[i][j]);
            }
        }
        printf("\n");
    }

    
    traverseDownAndSum(0, 0, triangle, 0);
    
    printf("\nmaximum sum is %d\n", sum);
    printf("%d paths were traversed\n", iterationcount);
    return 0;
}


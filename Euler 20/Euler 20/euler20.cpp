//
//  main.cpp
//  Euler 20
//
//  Created by Aly Thobani on 16-01-18.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

 Find the sum of the digits in the number 100! */ 

#include <iostream>

int numbertofactorial = 10000; //confirmed works for at least 50000

void printCurrentProduct(int* product, int size) {
    
    int firstzeroinarray = size;
    while (product[firstzeroinarray-1] == 0) firstzeroinarray--;
    
    for (int i = firstzeroinarray-1; i >=0; i--) {
        printf("%d", product[i]);
    }
    printf("\n");
}

int sumDigits(int* product, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += product[i];
    return sum;
}

int* fixCarryIfNecessary(int* product, int index) {
    while (product[index] / 10 != 0) {
        int carry = product[index]/10;
        product[index+1] += carry;
        product[index] %= 10;
        index++;
    }
    return product;
}

int main(int argc, const char * argv[])
{
    int sizeofarray = 2*numbertofactorial;
    int* product;
    product = new int[sizeofarray];
    
    //initialize product array to 0s
    for (int i = 0; i < sizeofarray; i++) {
        product[i] = 0;
    }
    
    product[0] = 1;
    for (int multiplier = 2; multiplier <= numbertofactorial; multiplier++) {
        
//        printf("%d! = ", multiplier-1);
//        printCurrentProduct(product, sizeofarray);
//        ^uncomment above to see each factorial in succession^
        
        //find the index of the zero before the first nonzero
        int firstzeroinarray = sizeofarray;
        while (product[firstzeroinarray-1] == 0) firstzeroinarray--;
        
        int carry = 0;
        for (int index = 0; index < firstzeroinarray; index++) {
            product[index] = product[index]*multiplier + carry;
            if (product[index]/10 != 0) {
                carry = product[index]/10;
                product[index] %= 10;
            }
            else carry = 0;
        }
        product[firstzeroinarray] = carry;
        product = fixCarryIfNecessary(product, firstzeroinarray);
    }
    printf("\n%d! = ", numbertofactorial);
    printCurrentProduct(product, sizeofarray);
    int sum = sumDigits(product, sizeofarray);
    printf("The sum of the digits of %d! is %d.\n", numbertofactorial, sum);
    return 0;
}


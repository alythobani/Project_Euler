//
//  main.cpp
//  Euler 17
//
//  Created by Aly Thobani on 16-01-13.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//
/* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 
 NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage. */

#include <iostream>

int one = 3, two = 3, three = 5, four = 4, five = 4, six = 3, seven = 5, eight = 5, nine = 4;
int ten = 3, eleven = 6, twelve = 6, thirteen = 8, fifteen = 7, eighteen = 8;
int teen = 4;
int twenty = 6, thirty = 6, forty = 5, fifty = 5, sixty = 5, seventy = 7, eighty = 6, ninety = 6;
int hundred = 7, thousand = 8;

int sum;
int maxnumber = 1000;

void addDigit(int n) {
    switch (n) {
        case 1:
            sum += one;
            break;
        case 2:
            sum += two;
            break;
        case 3:
            sum += three;
            break;
        case 4:
            sum += four;
            break;
        case 5:
            sum += five;
            break;
        case 6:
            sum += six;
            break;
        case 7:
            sum += seven;
            break;
        case 8:
            sum += eight;
            break;
        case 9:
            sum += nine;
            break;
        default:
            break;
    }
}

void addTensNotTeen(int n) {
    switch (n) {
        case 2:
            sum += twenty;
            break;
        case 3:
            sum += thirty;
            break;
        case 4:
            sum += forty;
            break;
        case 5:
            sum += fifty;
            break;
        case 6:
            sum += sixty;
            break;
        case 7:
            sum += seventy;
            break;
        case 8:
            sum += eighty;
            break;
        case 9:
            sum += ninety;
            break;
        default:
            break;
    }
}

void addTeen(int n) {
    switch (n) {
        case 10:
            sum += ten;
            break;
        case 11:
            sum += eleven;
            break;
        case 12:
            sum += twelve;
            break;
        case 13:
            sum += thirteen;
            break;
        case 14:
            sum += four + teen;
            break;
        case 15:
            sum += fifteen;
            break;
        case 16:
            sum += six + teen;
            break;
        case 17:
            sum += seven + teen;
            break;
        case 18:
            sum += eighteen;
            break;
        case 19:
            sum += nine + teen;
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[])
{
    sum = 0;
    
    for (int i = 1; i <= maxnumber; i++) {
        if (i / 1000) { // i = 1000
            sum += one + thousand;
        }
        else if (i / 100) { // 100 <= i <= 999
            addDigit(i/100); // "___" hundred
            sum += hundred; // "hundred"
            if (i % 100) {
                sum += 3; // "and"
                if ((i % 100) / 10 == 1) {
                    addTeen(i % 100);
                }
                if (((i % 100) / 10) != 1) {
                    addTensNotTeen((i % 100)/10);
                    addDigit(i % 10);
                }
            }
        }
        else if (i / 10) { // 10 <= i <= 99
            if (i / 10 == 1) {
                addTeen(i);
            }
            if (i / 10 > 1) {
                addTensNotTeen(i/10);
                addDigit(i % 10);
            }
        }
        else { // 1 <= i <= 9
            addDigit(i);
        }
    }
    
    printf("sum is %d", sum);
    
    return 0;
}


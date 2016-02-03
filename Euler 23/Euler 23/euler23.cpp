//
//  main.cpp
//  Euler 23
//
//  Created by Aly Thobani on 16-02-02.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

int maximum_number_not_the_sum_of_two_abundant_numbers = 28123;

int sumProperDivisorsOfEvenNumber(int n) {
    int sum = 1;
    for (int i = 2; i <= n/i; i++) {
        if (n % i == 0) {
            sum += i + (n/i);
            if (i == n/i) sum -= i;
        }
    }
    return sum;
}

int sumProperDivisorsOfOddNumber(int n) {
    int sum = 1;
    for (int i = 3; i <= n/i; i = i + 2) {
        if (n % i == 0) {
            sum += i + (n/i);
            if (i == n/i) sum -= i;
        }
    }
    return sum;
}

int isAbundantNumber(int n) {
    if (n % 2 == 0) return (sumProperDivisorsOfEvenNumber(n) > n);
    else return (sumProperDivisorsOfOddNumber(n) > n);
}

int isTheSumOfTwoAbundantNumbers(int n, int* is_abundant_number_array) {
    for (int i = 12; 2*i <= n; i++) {
        if (is_abundant_number_array[i] && is_abundant_number_array[n-i]) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    
    int* is_abundant_number_array = new int[maximum_number_not_the_sum_of_two_abundant_numbers+1];
    
    for (int i = 1; i <= maximum_number_not_the_sum_of_two_abundant_numbers; i++) {
        is_abundant_number_array[i] = isAbundantNumber(i);
    }
    
    long sum_of_numbers_that_arent_the_sum_of_two_abundant_numbers = 28123*28124/2;

    for (int i = 1; i <= maximum_number_not_the_sum_of_two_abundant_numbers; i++) {
        if (isTheSumOfTwoAbundantNumbers(i, is_abundant_number_array)) {
            cout << "NOT: " << i << endl;
            sum_of_numbers_that_arent_the_sum_of_two_abundant_numbers -= i;
        }
    }
    
    cout << 28123*28124/2 << endl << "Sum of numbers that aren't the sum of two abundant numbers is " << sum_of_numbers_that_arent_the_sum_of_two_abundant_numbers << ".";
    
    return 0;
}


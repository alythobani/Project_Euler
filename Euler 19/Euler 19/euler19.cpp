//
//  main.cpp
//  Euler 19
//
//  Created by Aly Thobani on 16-01-18.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* You are given the following information, but you may prefer to do some research for yourself.
 
 1 Jan 1900 was a Monday.
 Thirty days has September,
 April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.
 A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)? */

#include <iostream>

// Start on Monday, January 1, 1900
int month = 0; //jan = 0, feb = 1, ..., dec = 11
int dayoftheweek = 1; //sunday = 0, monday = 1, ..., saturday = 6
int year = 1900; 

int sundaycount = 0;

int updateFirstOfTheMonthSundayCount(int dayoftheweek, int sundaycount) {
    if (dayoftheweek == 0) sundaycount++;
    return sundaycount;
}

int isLeapYear(int year) {
    if ((year % 400) == 0) return 1;
    if ((year % 100) == 0) return 0; 
    if ((year % 4) == 0) return 1;
    return 0;
}

void progressByAMonth() {
    if (month == 1) { //if february
        if (isLeapYear(year)) {
            dayoftheweek = (dayoftheweek + 29) % 7; //29 days in feb for a leap year
        }
    } //if not a leap year, since 28 is 0 mod 7 the day of the week does not change
    
    else if (month == 8 || month == 3 || month == 5 || month == 10) { //if sept, apr, june or nov
        dayoftheweek = (dayoftheweek + 30) % 7;
    }
    
    else {
        dayoftheweek = (dayoftheweek + 31) % 7;
    }
    month = (month + 1) % 12;
    if (month == 0) {
        year++;
    }
}

int main(int argc, const char * argv[])
{    
    //progress to 1 jan 1901
    while (year != 1901) {
        progressByAMonth();
    }
    
    while (year != 2001) {
        sundaycount = updateFirstOfTheMonthSundayCount(dayoftheweek, sundaycount);
        progressByAMonth();
        printf("Date is %d/01/%d\n", month, year);
    }
    
    printf("%d Sundays fell on the first of a month between 1 Jan 1901 and 31 Dec 2000.", sundaycount);
    
    return 0;
}


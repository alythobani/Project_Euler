//
//  main.cpp
//  Euler 22
//
//  Created by Aly Thobani on 16-01-18.
//  Copyright (c) 2016 __MyCompanyName__. All rights reserved.
//

/* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file? */

#include <iostream>
#include <fstream>
using namespace std;
#include <string>

int approxnumberofnames = 5000;

struct Name {
    string name;
    int lengthofname;
    int* valuesofnameletters;
    int alphabeticalvalue;
};

struct Name createNameStruct(string name) {
    struct Name namestruct;
    namestruct.name = name;
    
    int length = name.length();
    namestruct.lengthofname = length;
    namestruct.valuesofnameletters = new int[length];
    for (int i = 0; i < length; i++) {
        char& letter = name[i];
        int lettervalue = letter - 'A' + 1;
        namestruct.valuesofnameletters[i] = lettervalue;
    }
    
    namestruct.alphabeticalvalue = 0;
    for (int i = 0; i < length; i++) {
        namestruct.alphabeticalvalue += namestruct.valuesofnameletters[i];
    }
    
    return namestruct;
}

int isAlphabeticallySmaller(struct Name name, struct Name compareTo) {
    int lengtha = name.lengthofname;
    int lengthb = compareTo.lengthofname;
    int smallerLength = (lengtha < lengthb ? lengtha : lengthb);
    int i = 0;
    while (i < smallerLength) {
        int lettervaluea = name.valuesofnameletters[i];
        int lettervalueb = compareTo.valuesofnameletters[i++];
        if (lettervaluea < lettervalueb) return 1;
        if (lettervalueb < lettervaluea) return 0;
    }
    //at this point they match each other's first smallerLength letters
    return (lengtha < lengthb ? 1 : 0); //name is smaller only if it has fewer letters
}

struct Name * nameSwapJandJMinusOne(struct Name * namearray, int j) {
    struct Name tempname = namearray[j];
    namearray[j] = namearray[j-1];
    namearray[j-1] = tempname;
    return namearray;
}

struct Name * insertionSortNames(struct Name * namearray, int numberOfNames) {
    for (int i = 1; i < numberOfNames; i++) {
        int j = i;
        while (j > 0 && isAlphabeticallySmaller(namearray[j], namearray[j-1])) {
            namearray = nameSwapJandJMinusOne(namearray, j);
            j--;
        }
    }
    return namearray;
}

int main(int argc, const char * argv[])
{
    int sizeofarray = approxnumberofnames*2;
    struct Name * namearray = new struct Name[sizeofarray];
    for (int i = 0; i < sizeofarray; i++) {
        struct Name namestruct;
        namestruct.name = "";
        namestruct.alphabeticalvalue = 0;
    }
    
    ifstream file("/Users/athobani9/Desktop/Project Euler/Euler 22/Euler 22/names.txt");
    string str; 
    getline(file, str);
    size_t positionofopenquotes = str.find("\"");
    size_t positionofclosedquotes = str.find("\"", positionofopenquotes+1);
    int i = 0;
    while (positionofclosedquotes != string::npos && positionofopenquotes != string::npos) {
        string name = str.substr(positionofopenquotes+1, positionofclosedquotes-positionofopenquotes-1);
        namearray[i] = createNameStruct(name);
        positionofopenquotes = str.find("\"", positionofclosedquotes+1);
        positionofclosedquotes = str.find("\"", positionofopenquotes+1);
        i++;
    }
    
    int numberofnames = i;
    printf("%d\n", numberofnames);
    
//    for (int j = 0; j < numberofnames; j++) {
//        struct Name name = namearray[j];
//        cout << name.name << endl;
//    }
    
    namearray = insertionSortNames(namearray, numberofnames);
    int namescore_sum = 0;
    for (int j = 0; j < numberofnames; j++) {
        struct Name name = namearray[j];
        int namescore = (j+1)*name.alphabeticalvalue;
        namescore_sum += namescore;
    }

    cout << "Total sum of all the name scores is " << namescore_sum << ".";
    
    // insert code here...
    return 0;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

int main()
{
    //Initialize variables
    ifstream file;
    char comma = ',';
    char dash = '-';
    string line, first, second;
    int a1, a2, b1, b2;
    int part1, part2 = 0;

    //Open puzzle input
    file.open("Day4Input.txt");


    //Get input in the form of numbers dash numbers, commma, numbers dash numbers (ex: 1-6,3-9)
    //Split the string into four individual int values, first by splitting it into two strings, 
    //each containing a number, a dash, and another number
    //Then split those strings and use stoi to convert them to integers
    //Now we have a1 and a2, which are the first two numbers, and b1 and b2, which are the second
    //For part 1, we check if one of the ranges (a or b) completely contain the other
    //For part 2, we check if either of the ranges share at least one value
    while(file.good())
    {
        //Get a line from file
        getline(file, line);

        //Split string into two, remove comma
        first = line.substr(0, line.find(comma));
        second = line.substr(line.find(comma) + 1);

        //Split first string into two ints, remove dash
        a1 = stoi(first.substr(0, first.find(dash)));
        a2 = stoi(first.substr(first.find(dash) + 1));

        //Split second string into two ints, remove dash
        b1 = stoi(second.substr(0, second.find(dash)));
        b2 = stoi(second.substr(second.find(dash) + 1));

        //Check if a contains the entirety of b
        if(a1 <= b1 && a2 >= b2)
            part1++;

        //Check if b contains the entirety of a
        else if(b1 <= a1 && b2 >= a2)
            part1++;


        // Part 2
        //Check if a starts lower than b, that b starts before a ends
        if(a1 <= b1 && b1 <= a2)
            part2++;
        
        //Check if b starts lower than a, that a starts before b ends
        else if(b1 <= a1 && a1 <= b2)
            part2++;
    }

    cout << "Part 1: " << part1 << endl; // 453
    cout << "Part 2: " << part2 << endl; // 919

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

//Function takes in a string and finds if any of its characters
//repeat using nest for loops
//Returns true if no characters repeat
bool compare(string line)
{

    for(int i = 0; i < line.size(); i++)
        for(int j = i + 1; j < line.size(); j++)
            if(line.at(i) == line.at(j))
                return false;

    return true;
}

int main()
{
    //Initialize variables
    ifstream file;
    string line;
    string sub;


    //Open puzzle input
    file.open("Day6Input.txt");

    //Get a line from file
    getline(file, line);

    //Part 1
    //Starting from the beginning of the input, this loop pulls 
    //4 character substrings and sends them to function compare
    //If all 4 characters are unique, outputs the index of the last character
    for(int i = 0; i < line.size() - 4; i++)
    {
        sub = line.substr(i, 4);

        if(compare(sub))
        {
            cout << i + 4 << endl;
            i = line.size();
        }
    }

    //Part 2
    //Same as part 1 except with 14 characters
    for(int i = 0; i < line.size() - 4; i++)
    {
        sub = line.substr(i, 14);

        if(compare(sub))
        {
            cout << i + 14 << endl;
            i = line.size();
        }
    }

    //part 1 1356
    //part 2 2564

    return 0;
}
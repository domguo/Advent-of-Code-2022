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
    for(int i = 0; i < line.size() - 4; i++)
    {
        sub = line.substr(i, 4);

        if(compare(sub))
        {
            cout << i + 4 << endl;
            i = line.size();
        }
    }

    //Part 1
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




    return 0;
}
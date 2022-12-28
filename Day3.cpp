#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    //Initialize variables
    ifstream file;
    string line;
    int score = 0;
    //Alphabet in array for point values
    char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<char> array;


    //Open puzzle input
    file.open("Day3Input.txt");

    //While file is still good, split each line into halves, and compare each character in the strings
    //using nested for loops. If there's a match, push that character into the array, then set the indices
    //in the for loops to move onto the next line
    while(file.good())
    {
        getline(file, line);
        
        //Set sub to second half of string line, and line to first half
        string sub = line.substr(line.length()/2, line.length()/2);
        line = line.substr(0, line.length()/2);

        //Nested for loop to search for matching character
        for(int i = 0; i < line.length(); i++)
            for(int j = 0; j < line.length(); j++)
                if(line.at(i) == sub.at(j))
                    {
                        //Push back matching characters and end loops
                        array.push_back(line.at(i));
                        i = j = line.length();
                    }
    }

    //Iterate through vector to find point value in alphabet arrays
    for(int i = 0; i < array.size(); i++)
    {
        for(int j = 1; j <= 26; j++)
        {
            //If found in lowercase array, add point values based on array index and
            //exit out of loop
            if(array[i] == lower[j-1])
            {
                score += j;
                j = 27;
            }

            //If found in uppercase array, do the same as lowercase but add 26
            else if(array[i] == upper[j-1])
            {
                score += j + 26;
                j = 27;
            }
        }
    }

    cout << score << endl; //8298

    //Part 2

    //Close and reopen file to read again
    file.close();
    file.open("Day3Input.txt");

    //Reset variables
    array.clear();
    score = 0;

    //This time, read three three lines at a time and used nested for loops to
    //find the character they share, and push value to the array
    while(file.good())
    {
        string line1;
        string line2;
        string line3;

        getline(file, line1);
        getline(file, line2);
        getline(file, line3);

        for(int i = 0; i < line1.length(); i++)
            for(int j = 0; j < line2.length(); j++)
                if(line1.at(i) == line2.at(j))
                    for(int k = 0; k < line3.length(); k++)
                        if(line1.at(i) == line3.at(k))
                        {
                            array.push_back(line1.at(i));
                            i = j = k = INT_MAX;
                        }
    }

    //Use the same search for alphabet arrays to find point values and sum them
    for(int i = 0; i < array.size(); i++)
    {
        for(int j = 1; j <= 26; j++)
        {
            if(array[i] == lower[j-1])
            {
                score += j;
                j = 27;
            }

            else if(array[i] == upper[j-1])
            {
                score += j + 26;
                j = 27;
            }
        }
    }

    cout << score << endl; //2708

    return 0;
}
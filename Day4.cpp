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
    // string line = "1234-4624,543-157";
    char comma = ',';
    char dash = '-';
    string line, first, second;
    int a1, a2, b1, b2;
    int part1, part2 = 0;

    //Open puzzle input
    file.open("Day4Input.txt");


    while(file.good())
    {
        getline(file, line);

        first = line.substr(0, line.find(comma));
        second = line.substr(line.find(comma) + 1);

        cout << first << " x " << second << endl;

        a1 = stoi(first.substr(0, first.length() - first.find(dash)));
        a2 = stoi(first.substr(first.find(dash) + 1));

        b1 = stoi(second.substr(0, second.length() - second.find(dash)));
        b2 = stoi(second.substr(second.find(dash) + 1));

        // cout << a1 << endl;
        // cout << a2 << endl;
        // cout << b1 << endl;
        // cout << b2 << endl;

        // if(a1 > a2)
        //     swap(a1, a2);
        
        // if(b1 > b2)
        //     swap(b1, b2);
        
        if(a1 <= b1 && a2 >= b2)
        {
            part1++;
            // cout << line << "A" << endl;
        }

        else if(b1 <= a1 && b2 >= a2)
        {
            part1++;
            // cout << line << "B" << endl;
        }

        // Part 2
        if(a2 >= b1 || b2 >= a1)
            part2++;
    }


    cout << "Part 1: " << part1 << endl; // 453
    cout << "Part 2: " << part2 << endl;

    //Part 2 integrated into code


    return 0;
}
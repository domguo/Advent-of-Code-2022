#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

void initializeArray(stack<char>* arr)
{
    arr[1].push('Z');
    arr[1].push('N');

    arr[2].push('M');
    arr[2].push('C');
    arr[2].push('D');

    arr[3].push('P');

    // arr[1].push('D');
    // arr[1].push('T');
    // arr[1].push('W');
    // arr[1].push('F');
    // arr[1].push('J');
    // arr[1].push('S');
    // arr[1].push('H');
    // arr[1].push('N');

    // arr[2].push('H');
    // arr[2].push('R');
    // arr[2].push('P');
    // arr[2].push('Q');
    // arr[2].push('T');
    // arr[2].push('N');
    // arr[2].push('B');
    // arr[2].push('G');

    // arr[3].push('L');
    // arr[3].push('Q');
    // arr[3].push('V');

    // arr[4].push('N');
    // arr[4].push('B');
    // arr[4].push('S');
    // arr[4].push('W');
    // arr[4].push('R');
    // arr[4].push('Q');

    // arr[5].push('N');
    // arr[5].push('D');
    // arr[5].push('F');
    // arr[5].push('T');
    // arr[5].push('V');
    // arr[5].push('M');
    // arr[5].push('B');

    // arr[6].push('M');
    // arr[6].push('D');
    // arr[6].push('B');
    // arr[6].push('V');
    // arr[6].push('H');
    // arr[6].push('T');
    // arr[6].push('R');

    // arr[7].push('D');
    // arr[7].push('B');
    // arr[7].push('Q');
    // arr[7].push('J');

    // arr[8].push('D');
    // arr[8].push('N');
    // arr[8].push('J');
    // arr[8].push('V');
    // arr[8].push('R');
    // arr[8].push('Z');
    // arr[8].push('H');
    // arr[8].push('Q');

    // arr[9].push('B');
    // arr[9].push('N');
    // arr[9].push('H');
    // arr[9].push('M');
    // arr[9].push('S');

}

void printArr(stack<char>* arr)
{
    for(int i = 1; i < 10; i++)
    {
        while(arr[i].empty() == false)
        {
            cout << arr[i].top() << " ";
            arr[i].pop();
        }

        cout << endl;
    }
}

void move(stack<char>* arr, int num, int from, int to)
{

    if(num > arr[from].size())
        num = arr[from].size();

    for(int i = 0; i < num; i++)
    {
        char hold = arr[from].top();
        arr[from].pop();
        arr[to].push(hold);
    }
} 

int main()
{
    //Initialize variables
    ifstream file;
    stack<char> arr[10];
    string line = "move 3 from 1 to 2";
    int num, from, to;

    // //Initialize the stack array
    initializeArray(arr);

    move(arr, 3, 2, 5);


    //Open puzzle input
    file.open("Day5Input.txt");


    while(file.good())
    {
        //Get a line from file
        getline(file, line);

        line = line.substr(5);

        num = stoi(line.substr(0, ' '));

        line = line.substr(line.find(' ') + 6);

        from = stoi(line.substr(0, 1));
        to = stoi(line.substr(5));

        move(arr, num, from, to);


    }

    printArr(arr);
    
    // for(int i = 1; i < 10; i++)
    //     cout << arr[i].top();

    

    return 0;
}
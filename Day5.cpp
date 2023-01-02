#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

void initializeArray(stack<char>* arr)
{
    arr[1].push('D');
    arr[1].push('T');
    arr[1].push('W');
    arr[1].push('F');
    arr[1].push('J');
    arr[1].push('S');
    arr[1].push('H');
    arr[1].push('N');

    arr[2].push('H');
    arr[2].push('R');
    arr[2].push('P');
    arr[2].push('Q');
    arr[2].push('T');
    arr[2].push('N');
    arr[2].push('B');
    arr[2].push('G');

    arr[3].push('L');
    arr[3].push('Q');
    arr[3].push('V');

    arr[4].push('N');
    arr[4].push('B');
    arr[4].push('S');
    arr[4].push('W');
    arr[4].push('R');
    arr[4].push('Q');

    arr[5].push('N');
    arr[5].push('D');
    arr[5].push('F');
    arr[5].push('T');
    arr[5].push('V');
    arr[5].push('M');
    arr[5].push('B');

    arr[6].push('M');
    arr[6].push('D');
    arr[6].push('B');
    arr[6].push('V');
    arr[6].push('H');
    arr[6].push('T');
    arr[6].push('R');

    arr[7].push('D');
    arr[7].push('B');
    arr[7].push('Q');
    arr[7].push('J');

    arr[8].push('D');
    arr[8].push('N');
    arr[8].push('J');
    arr[8].push('V');
    arr[8].push('R');
    arr[8].push('Z');
    arr[8].push('H');
    arr[8].push('Q');

    arr[9].push('B');
    arr[9].push('N');
    arr[9].push('H');
    arr[9].push('M');
    arr[9].push('S');

}

void move(stack<char>* arr, int num, int from, int to)
{

    //Can't move more crates than there are crates from a stack
    //Set number of crates to move to the lower value
    if(num > arr[from].size())
        num = arr[from].size();

    //Move crates from one stack to the other
    for(int i = 0; i < num; i++)
    {
        char hold = arr[from].top();
        arr[from].pop();
        arr[to].push(hold);
    }
} 

void move2(stack<char>* arr, int num, int from, int to)
{
    //Initialize temp stack
    stack<char> stack;

    //Can't move more crates than there are crates from a stack
    //Set number of crates to move to the lower value
    if(num > arr[from].size())
        num = arr[from].size();

    //Take crates from origin stack and push them into temp stack
    for(int i = 0; i < num; i++)
    {
        char hold = arr[from].top();
        arr[from].pop();
        stack.push(hold);
    }

    //Push crates from temp stack to the destination stack
    for(int i = 0; i < num; i++)
    {
        char hold = stack.top();
        stack.pop();
        arr[to].push(hold);
    }
} 

int main()
{
    //Initialize variables
    ifstream file;
    stack<char> arr1[10];   //Part 1
    stack<char> arr2[10];   //Part 2
    string line;
    int num, from, to;

    //Initialize the stack arrays
    initializeArray(arr1);
    initializeArray(arr2);

    //Open puzzle input
    file.open("Day5Input.txt");

    //Keep pulling instructions from input file and perform the actions
    while(file.good())
    {
        //Get a line from file
        getline(file, line);

        //split input lines into integers for number of crates to move,
        //from which stack, and to which stack
        line = line.substr(5);

        num = stoi(line.substr(0, ' '));

        line = line.substr(line.find(' ') + 6);

        from = stoi(line.substr(0, 1));
        to = stoi(line.substr(5));

        //Call functions for part 1 and part 2 moves
        move(arr1, num, from, to);
        move2(arr2, num, from, to);
    }
    
    //Answer asks for top crate of each stack
    //Part 1 answer GRTSWNJHH
    for(int i = 1; i < 10; i++)
    {
        if(arr1[i].size() > 0)
            cout << arr1[i].top();
    }

    cout << endl;

    //Part 2 answer QLFQDBBHM
    for(int i = 1; i < 10; i++)
    {
        if(arr2[i].size() > 0)
            cout << arr2[i].top();
    }

    return 0;
}
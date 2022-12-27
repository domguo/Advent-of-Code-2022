#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main()
{

    //Initialize variables
    ifstream file;
    vector<int> arr;
    string line;

    //Open puzzle input
    file.open("Day1Input.txt");

    //While the file still has contents, keep pulling text from it
    //Add the numbers together and once it reaches a new line,
    //Push sum of the numbers pulled into a vector
    while(file.good())
    {
        int temp;
        getline(file, line);

        if(line.empty() == false)
            temp += stoi(line);

        else
        {
            arr.push_back(temp);
            temp = 0;
        }

    }

    int max = arr[0];

    //Search array for largest value
    for(int i = 1; i < arr.size(); i++)
        if(arr[i] > max)
            max = arr[i];

    cout << max << endl; //Part 1 answer 70698

    ///Begin part 2

    //Sort array
    sort(arr.begin(), arr.end());

    //Output the sum of the 3 largest values of the array
    cout << arr[arr.size()-1] + arr[arr.size()-2] + arr[arr.size()-3] << endl;

    //Part 2 answer 206643

    return 0;
}
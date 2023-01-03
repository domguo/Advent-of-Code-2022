#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

class node
{
    public:
    string name;
    vector<node*> dir;
    int files;
    node* up;
    int total;

    node(string name)
    {
        this->name = name;
        files = 0;
    }

    void addDir(string name)
    {
        node* temp = new node(name);
        
        temp->up = this;

        dir.push_back(temp);
    }

    void addFile(int num)
    {
        total += num;
    }

    int getTotal()
    {
        return total;
    }

    node* move(string name)
    {
        for(int i = 0; i < dir.size(); i++)
            if(dir[i]->name == name)
                return dir[i];

        return NULL;
    }

};

int main()
{
    //Initialize variables
    ifstream file;
    string line;
    string sub;


    //Open puzzle input
    file.open("Day7Input.txt");

    //Get a line from file
    getline(file, line);

    node* ptr;

    ptr = new node("/");

    cout << line.substr(2, 2) << endl;

    getline(file, line);

    // //Add everything in
    while(file.good())
    {
        getline(file, line);

        cout << line << endl;

        //If command is cd
        if(line.substr(2, 2) == "cd")
        {
            cout << "changing directories" << endl;
            ptr = ptr->move(line);

        }

        //If command is ls
        else if(line.substr(2, 2) == "ls")
        {
            ;
        }

        else
        {
            // getline(file, line);

            // cout << line << endl;

            if(line.substr(0, 3) == "dir")
            {
                cout << "Adding a directory" << endl;
                ptr->addDir(line.substr(3));
            }

            else
            {
                cout << "Adding a file" << endl;
                ptr->addFile(stoi(line.substr(0, line.find(' '))));
            }
        }
    }

    //Calculate sizes

    //

    return 0;
}
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

    //Open puzzle input
    file.open("Day2Input.txt");

    //While the file still has values, pull each line and look at the characters
    //If the other player (him) plays A (rock), B (paper), or C (scissors)
    //and I play X (rock), Y (paper), or Z (scissors), assign points accordingly
    //If I play X, I get 1 point, Y 2 points, and Z 3 points
    //I also get 0 points of I lose against him, 3 points if I die, and 6 points if I win
    while(file.good())
    {
        getline(file, line);

        char him = line.at(0);

        char me = line.at(2);

        //Case if I play rock
        if(me == 'X')
        {
            //Earn one point for playing rock
            score++;

            //If opponent plays rock, game ties and earn 3 points
            if(him == 'A')
                score += 3;
            
            //If opponent plays scissors, we win and earn 6 points
            else if(him == 'C')
                score += 6;


        }
        
        //Case if I play paper
        else if(me == 'Y')
        {
            //Earn 2 points for playing paper
            score += 2;

            //If opponent plays rock, we win and earn 6 points
            if(him == 'A')
                score += 6;

            //If opponent plays paper, game ties and we earn 3 points
            else if(him == 'B')
                score += 3;

        }
        
        //Case if I play scissors
        else
        {
            //Earn 3 points for playing scissors
            score += 3;

            //If opponent plays paper, we win and earn 6 points
            if(him == 'B')
                score += 6;
            
            //If opponent plays scissors, game ties and we earn 3 points
            else if(him == 'C')
                score += 3;
        }        
    }

    cout << score << endl; //12794

    //Begin part 2

    //Close and reopen files to read again
    file.close();
    file.open("Day2Input.txt");

    //Reset score
    score = 0;

    
    while(file.good())
    {
        getline(file, line);

        char him = line.at(0);

        char me = line.at(2);

        //If opponent plays rock
        if(him == 'A')
        {
            //If I need to lose
            //I should play scissors
            //Earn 3 points for scissors
            if(me == 'X')
                score += 3;

            //If I need to tie
            //I should play rock
            //Earn 4 points (rock + draw)
            else if(me == 'Y')
                score += 4;

            //If I need to win
            //I should play paper
            //Earn 8 points (paper + win)
            else
                score += 8;
        }

        //If opponent plays paper
        else if(him == 'B')
        {
            //If I need to lose
            //I should play rock
            //Earn 1 point for rock
            if(me == 'X')
                score++;

            //If I need to tie
            //I should play paper
            //Earn 5 points (paper + draw)
            else if(me == 'Y')
                score += 5;

            //If I need to win
            //I should play scissors
            //Earn 9 points (scissors + win)
            else
                score += 9;
        }

        //If opponent plays scissors
        else
        {
            //If I need to lose
            //I should play paper
            //Earn 3 points for paper
            if(me == 'X')
                score += 2;

            //If I need to tie
            //I should play scissors
            //Earn 4 points (scissors + draw)
            else if(me == 'Y')
                score += 6;

            //If I need to win
            //I should play rock
            //Earn 7 points (rock + win)
            else
                score += 7;
        }
    }

    cout << score << endl;  //14979

    return 0;
}
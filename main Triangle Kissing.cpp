/* Name: Samiksha Pradhan
   Course: CS 372
   Project: Triangles Kissing */

#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile;

void space(int sp)
{
    if(sp==0)
        return;
    else
    {
        cout << " ";
        outfile << " ";
        space(sp-1);
    }
}

void row(char first, char last, int sp)
{
    if(first == last)
    {
        cout << last;
        outfile << last;
        return;
    }
    else
    {
        cout << first;
        outfile << first;
        row(first+1, last, sp-1);
        cout << first; // returns in reverse order
        outfile << first;
    }
}

void bigToSmall(char first, char last, int sp)
{
    if(first > last)
    {
        return;
    }
    else
    {
        cout << endl;
        outfile << endl;
        space(sp);
        row(first, last, sp);
        bigToSmall(first, last-1, sp+1);
    }
}

void smallToBig(char first, char last, int sp)
{
    if(first > last)
    {
        return;
    }
    else
    {
        smallToBig(first, last-1, sp+1);
        cout << endl;
        outfile << endl;
        space(sp);
        row(first, last, sp);
    }
}
int main()
{
    outfile.open("Triangles Kissing Output.txt");

    smallToBig('a','f',0);
    bigToSmall('a','f',0);

    cout << "\n" << endl;
    outfile << "\n" << endl;

    bigToSmall('a','f',0);
    smallToBig('a','f',0);

    cout << "\n" << endl;
    return 0;
}

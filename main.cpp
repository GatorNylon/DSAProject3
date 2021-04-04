#include <iostream>
#include "Emissions.h"
#include "ShellSort.h"
using namespace std;
// include data-structure class files


int main()
{
    int year, option;

    cout << "Welcome to EmmissionSort!" << endl;
    cout << "Select from one of the following years: " << endl
        << "1. 2019" << endl << "2. 2018" << endl;

    cin >> year;
    if (year == 1)
        year = 2019;
    else
        year = 2018;

    // read file data into Data Structures based on year

    cout << endl << "Sort By: " << endl
        << "1. State " << endl 
        << "2. Zip Code" << endl
        << "3. Chemical Name" << endl
        << "4. Emmisions Amount" << endl;
    cin >> option;

    switch (option)
    {
    
    case(1):
        break;
    case(2):
        break;
    case(3):
        break;
    case(4):
        break;

    default:
        break;
    }


    
}

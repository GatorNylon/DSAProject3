#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Emissions.h"
using namespace std;



void Shellsort(vector<Emissions>& ve, function<bool(Emissions, Emissions)> lessThan)
{
	int gap = ve.size() / 2;

	while (gap > 0)
	{
		int cur_pos = gap;
		while (cur_pos < ve.size())
		{ //insertion sort
			auto cur_pos_val = ve[cur_pos];
			int prev_pos = cur_pos;
			
			while (prev_pos >= gap && lessThan(cur_pos_val, ve[prev_pos - gap]))
			{ // find smallest element of for inserstion of cur_pos_val
				ve[prev_pos] = ve[prev_pos - gap];	//ve[prev_pos] shifted in list with gaps
				prev_pos -= gap; 
			}

			ve[prev_pos] = cur_pos_val; // swap
			cur_pos += 1;
		}
		gap /= 2;
	}
}


bool lessThan_totalRelease(Emissions a, Emissions b)
{
	return (a.getTotalReleases() < b.getTotalReleases());
}

bool lessThan_state(Emissions a, Emissions b)
{
	int val = a.getState().compare(b.getState());
	if (val < 0)
		return true;
	else
		return false;
}

bool lessThan_zipCode(Emissions a, Emissions b)
{
	return (a.getZip() < b.getZip());
}

bool lessThan_City(Emissions a, Emissions b)
{
	int val = a.getCity().compare(b.getCity());
	if (val < 0)
		return true;
	else
		return false;
}

bool lessThan_Chemical(Emissions a, Emissions b)
{
	int val = a.getChemical().compare(b.getChemical());
	if (val < 0)
		return true;
	else
		return false;
}

void test_Shellsort_Emissions()
{
	vector<Emissions> ve; // = { 7 , 4 , 9 , 3 , 2 , 8 , 6 , 5 };
	ve.push_back(Emissions(7));
	ve.push_back(Emissions(4));
	ve.push_back(Emissions(9));
	ve.push_back(Emissions(3));
	ve.push_back(Emissions(2));
	ve.push_back(Emissions(8));
	ve.push_back(Emissions(6));
	ve.push_back(Emissions(7));
	ve.push_back(Emissions(7));
	ve.push_back(Emissions(5));
	ve.push_back(Emissions(4));


	cout << "Initial Input :";
	for (auto i : ve)
		cout << i.getTotalReleases() << " ";
	cout << endl;

	Shellsort(ve, lessThan_totalRelease); 

	cout << "Sorted Output :";
	for (auto i : ve)
		cout << i.getTotalReleases() << " ";
	cout << endl << endl;
}

void test_Shellsort_State()
{
	vector<Emissions> ve; 
	ve.push_back(Emissions("Florida"));
	ve.push_back(Emissions("California"));
	ve.push_back(Emissions("Utah"));
	ve.push_back(Emissions("Michigan"));
	ve.push_back(Emissions("New York"));
	ve.push_back(Emissions("New Jersey"));
	ve.push_back(Emissions("Missouri"));
	ve.push_back(Emissions("Arkansas"));
	


	cout << "Initial Input :";
	for (auto i : ve)
		cout << i.getState() << " ";
	cout << endl;

	Shellsort(ve, lessThan_state); // need to fix this 

	cout << "Sorted Output :";
	for (auto i : ve)
		cout << i.getState() << " ";
	cout << endl << endl;
}


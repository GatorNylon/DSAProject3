#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Emissions.h"
using namespace std;


void swap(vector<Emissions>& ve, int pos_a, int pos_b)
{
	auto temp = ve[pos_b];
	ve[pos_b] = ve[pos_a];
	ve[pos_a] = temp;
}

void Shellsort(vector<Emissions>& ve, function<bool(Emissions, Emissions)> lessThan)
{
	int gap = ve.size() / 2;

	while (gap > 0)
	{
		int cur_pos = 0;
		while (cur_pos < ve.size() and cur_pos + gap < ve.size()) // swap elements as long as they are both in container
		{
			if (lessThan(ve[cur_pos + gap], ve[cur_pos])) // if following element is less than previous element
			{
				swap(ve, cur_pos, cur_pos + gap);// swap them

				//check if the preceding elements up to the current element are still in order after swap
				// ----------------------------------------
				int prev_pos = 0;
				while (prev_pos < cur_pos and prev_pos + gap < ve.size())
				{
					if (lessThan(ve[prev_pos + gap], ve[prev_pos]))
					{
						swap(ve, prev_pos, prev_pos + gap); 
					}
					prev_pos++;
				}
				// ---------------------------------------
			}
			cur_pos++;
		}
		gap = gap / 2;
	}
}


//Misc...
void swap(vector<int>& ve, int pos_a, int pos_b)
{
	int temp = ve[pos_b];
	ve[pos_b] = ve[pos_a];
	ve[pos_a] = temp;
}
void Shellsort(vector<int>& ve)
{
	int gap = ve.size() / 2;

	while (gap > 0)
	{
		int cur_pos = 0;
		while (cur_pos < ve.size() and cur_pos + gap < ve.size()) // swap elements as long as they are both in container
		{
			if (ve[cur_pos + gap] < ve[cur_pos]) // if following element is less than previous element
			{
				swap(ve, cur_pos, cur_pos + gap); // swap them

				//check if the preceding elements up to the current element are still in order after swap
				// ----------------------------------------
				int prev_pos = 0;
				while (prev_pos < cur_pos and prev_pos + gap < ve.size())
				{
					if (ve[prev_pos + gap] < ve[prev_pos])
					{
						swap(ve, prev_pos, prev_pos + gap);
					}
					prev_pos++;
				}
				// ---------------------------------------
			}
			cur_pos++;
		}
		gap = gap / 2;
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
	ve.push_back(Emissions(5));
	ve.push_back(Emissions(4));


	cout << "Initial Input :";
	for (auto i : ve)
		cout << i.getTotalReleases() << " ";
	cout << endl;

	auto sorted = Shellsort(ve, lessThan_totalRelease); // need to fix this 

	cout << "Sorted Output :";
	for (auto i : sorted)
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

	auto sorted = Shellsort(ve, lessThan_state); // need to fix this 

	cout << "Sorted Output :";
	for (auto i : sorted)
		cout << i.getState() << " ";
	cout << endl << endl;
}

void test_Shellsort_int()
{
	vector<int> ve = { 7 , 4 , 9 , 3 , 2 , 8 , 6 , 5 };

	cout << "Initial Input :";
	for (int i : ve)
		cout << i << " ";
	cout << endl;

	Shellsort(ve);

	cout << "Sorted Output :";
	for (int i : ve)
		cout << i << " ";
	cout << endl << endl;
}
#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Emissions.h"
using namespace std;

void swap(vector<int>& ve, int pos_a, int pos_b)
{
	int temp = ve[pos_b];
	ve[pos_b] = ve[pos_a];
	ve[pos_a] = temp;
}

void swap(vector<Emissions>& ve, int pos_a, int pos_b)
{
	auto temp = ve[pos_b];
	ve[pos_b] = ve[pos_a];
	ve[pos_a] = temp;
}

void Shellsort(vector<int> &ve) 
{
	int gap = ve.size()/2;

	while (gap > 0)
	{
		int cur_pos = 0;
		while(cur_pos < ve.size() and cur_pos + gap < ve.size()) // swap elements as long as they are both in container
		{
			if (ve[cur_pos + gap] < ve[cur_pos]) // if following element is greater than previous element
			{
				swap(ve, cur_pos , cur_pos + gap);

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

// not tested yet
// greater need to be a function defined in Emmisions Class
void Shellsort(vector<Emissions>& ve, function<bool(int a, int b)> greater)
{
	int gap = ve.size() / 2;

	while (gap > 0)
	{
		int cur_pos = 0;
		while (cur_pos < ve.size() and cur_pos + gap < ve.size()) // swap elements as long as they are both in container
		{
			if (greater(cur_pos + gap, cur_pos)) // if following element is greater than previous element
			{
				swap(ve, cur_pos, cur_pos + gap);

				//check if the preceding elements up to the current element are still in order after swap
				// ----------------------------------------
				int prev_pos = 0;
				while (prev_pos < cur_pos and prev_pos + gap < ve.size())
				{
					if (greater(prev_pos + gap, prev_pos))
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


	cout << "Initial Input :";
	for (auto i : ve)
		cout << i.getTotalReleases() << " ";
	cout << endl;

	//Shellsort(ve, Emissions::greaterThan); // need to fix this 

	cout << "Sorted Output :";
	for (auto i : ve)
		cout << i.getTotalReleases() << " ";
	cout << endl << endl;
}

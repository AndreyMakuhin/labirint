//
//  main.cpp
//  icenbaev
//
//  Created by Андрей Макухин on 22.11.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct personI
{
	string name;
	int iNumber;
};

string sGuru = "Isenbaev";

vector<string> input_names;
vector<string> names;
vector<vector<string>> teams;
vector<vector<int>> graf;
vector<personI> personsIsinbaev;

void CheckRelationships(int index, int numberI);

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
	bool haveGuru = true;

    int n;
    cin >> n;	

	for (int i = 0; i < n; i++)
	{
		teams.push_back(vector<string>());
	}
    
    string recent;
	int teamsCount = 0;
	int peopleCount = 0;
    while(cin >> recent)
    {
		if (peopleCount != 0 && peopleCount % 3 == 0)
			teamsCount++;
		teams[teamsCount].push_back(recent);
        input_names.push_back(recent);
		peopleCount++;
    }
    
	if (find(input_names.begin(), input_names.end(), sGuru) != input_names.end())
	{
		names.push_back(sGuru);		
	}
	else
	{
		haveGuru = false;
	}
		

    for(string s : input_names)
    {
        if(find(names.begin(), names.end(), s) == names.end())
        {
            names.push_back(s);
        }
    }
    
    for (int y = 0; y < names.size(); y++ )
    {
        graf.push_back(vector<int>(names.size(), -1));
    }
	if (haveGuru)
	{
		for (int x = 0; x < names.size(); x++)
		{
			graf[x][0] = 0;
		}
	}
		
    
	if(haveGuru)
		CheckRelationships(0, 0);


	///доработка после основного алгоритма, для корректного вывода
	if (haveGuru)
	{
		personsIsinbaev.push_back({ sGuru, 0 });
	}
	

	for (int x = 0; x < names.size(); x++)
	{
		if (graf[0][x] == -1)
		{
			string un = names[x];
			personsIsinbaev.push_back({un, -1});
		}
	}

	 for(int i = 0; i < personsIsinbaev.size() - 1; i++)
		 for (int j = 0; j < personsIsinbaev.size() - i - 1; j++)
		 {
			 if (personsIsinbaev[j].name > personsIsinbaev[j + 1].name)
			 {
				 personI temp = personsIsinbaev[j];
				 personsIsinbaev[j] = personsIsinbaev[j + 1];
				 personsIsinbaev[j + 1] = temp;
			 }
		 }
    
    /////////это дебаг////////
   
    ///////////это дебаг///////

	for (personI p : personsIsinbaev)
	{
		cout << p.name << " ";
		if (p.iNumber != -1)
		{
			cout << p.iNumber;
		}
		else
		{
			cout << "undefined";
		}
		cout << endl;
	}	
    
    return 0;
}

void CheckRelationships(int index, int numberI)
{
    numberI++;
    string pivotName = names[index];
    string name;
	vector<string> coops;

	for (vector<string> v : teams)
	{
		if (find(v.begin(), v.end(), pivotName) != v.end())
		{
			for (string n : v)
			{
				int indexN = distance(names.begin(), find(names.begin(), names.end(), n));
				if (n != pivotName && find(coops.begin(), coops.end(), n) == coops.end() && graf[index][indexN]== -1)
				{
					coops.push_back(n);
					personsIsinbaev.push_back({n, numberI});
					for (int y = 0; y < names.size(); y++)
					{
						graf[y][indexN] = numberI;
					}
					
				}
			}
		}
	}	

	if (!coops.empty())
	{
		for (string n : coops)
		{
			int ind = 0;
			for (string s : names)
			{
				if (s == n)
					break;
				ind++;
			}
			CheckRelationships(ind, numberI);
		}
	}   
	
}

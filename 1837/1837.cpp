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
    
    int n;
    cin >> n;

	for (int i = 0; i < n; i++)
	{
		teams.push_back(vector<string>(3));
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
    
    names.push_back(sGuru);
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
    
    CheckRelationships(0, 0);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /////////это дебаг////////
    /*for(string s : names)
    {
        cout << s << " ";
    }

	cout << "\n\n";
    
	for (vector<string> v : teams)
	{
		for(string s : v)
			cout << s << " ";
		cout << "\n";
	}*/
    
    for (personI p : personsIsinbaev)
    {
        cout << p.name << " " << p.iNumber << "\n";
    }
    
    for(vector<int> y : graf)
    {
        for (int x : y)
        {
            cout << x;
        }
        cout << "\n";
    }

	cout << "\n\n";
    ///////////это дебаг///////
    
    return 0;
}

void CheckRelationships(int index, int numberI)
{
    numberI++;
    string pivotName = names[index];
    string name;
    for(int i = 0; i < names.size(); i++)
    {
        if(i != index )
        {
            name = names[i];
        }
        for(vector<string> v : teams)
        {
            for(string n : v)
            {
                if(n == name)
                {
                    for(string p : v)
                    {
                        if(p == pivotName && graf[index][i] < 0)
                        {
                            graf[index][i] = numberI;
                            personsIsinbaev.push_back({name, numberI});
                            CheckRelationships(i, numberI);
                        }
                    }
                }
            }
        }
    }
}

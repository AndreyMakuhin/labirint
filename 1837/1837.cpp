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

struct grafNode
{
	string name;
	int iNumber;
};

vector<string> input_names;
vector<string> names;
vector<vector<string>> teams;
vector<vector<grafNode>> graf;

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

	for (string s : names)
	{
			
	}
    
    for(string s : input_names)
    {
        if(s != "Isenbaev" && find(names.begin(), names.end(), s) == names.end())
        {
            names.push_back(s);
        }
    }
    
    for(string s : names)
    {
        cout << s << " ";
    }

	cout << "\n\n";
    
	for (vector<string> v : teams)
	{
		for(string s : v)
			cout << s << " ";
		cout << "\n";
	}

	cout << "\n\n";

    if(names.empty())
    {
        cout << "Empty\n";
    }
    
    
    return 0;
}

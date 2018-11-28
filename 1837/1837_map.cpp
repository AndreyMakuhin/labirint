//
//  1837_map.cpp
//  icenbaev
//
//  iCreated by Андрей Макухин on 28.11.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> graf;
vector<string> names;
vector<vector<string>> teams;
queue<string> myQ;

const string guru = "Isenbaev";

int nTeams;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "wt", stdout);
#endif
    
    bool isGuru = false;
    
    cin >> nTeams;
    
    for (int i = 0; i < nTeams; i++)
    {
        teams.push_back(vector<string>());
    }
    
    string sInput;
    int countInput = 0;
    int teamsCount = 0;
    while(cin >> sInput)
    {
        if (countInput != 0 && countInput % 3 == 0)
            teamsCount++;
        teams[teamsCount].push_back(sInput);
        countInput++;
        
        if(find(names.begin(), names.end(), sInput) == names.end())
        {
            names.push_back(sInput);
        }
        if(sInput == guru)
        {
            isGuru = true;
        }        
    }
    
    for(string s : names)
    {
        graf.insert({s, -1});
    }
    
    if(isGuru)
    {
        myQ.push(guru);
        graf[guru] = 0;
    }
    
    while(!myQ.empty())
    {
        string recent = myQ.front();
        int numIsen = graf[recent];
        vector<string> coop;
        
        for(vector<string> t : teams)
        {
            if(find(t.begin(), t.end(), recent)!= t.end())
            {
                for(string n : t )
                {
                    if(n!=recent && graf[n] == -1)
                    {
                        graf[n] = numIsen + 1;
                        coop.push_back(n);
                    }
                }
            }
        }
        
        for(string s : coop)
        {
            myQ.push(s);
        }
        
        myQ.pop();
    }
    
    sort(names.begin(), names.end());
    
    for (string s : names)
    {
        cout << s << " ";
        if(graf[s] == -1)
        {
            cout << "undefined\n";
        }
        else
        {
            cout << graf[s] << endl;
        }
    }
    
    return 0;
}

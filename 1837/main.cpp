//
//  main.cpp
//  icenbaev
//
//  Created by Андрей Макухин on 22.11.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> input_names;
vector<string> names;
//vector<string[3]> teams;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    cin >> n;
    
    string recent;
    while(cin >> recent)
    {
        input_names.push_back(recent);
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
    
    if(names.empty())
    {
        cout << "Empty\n";
    }
    
    
    return 0;
}

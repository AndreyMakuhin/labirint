//
//  main.cpp
//  kvartals
//
//  Created by Андрей Макухин on 07.12.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#include <iostream>

using namespace std;

int n, m;
double koef;

bool Cover(int min, int max, int minY, int maxY);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    int result = 0;
    cin >> n >> m;
    
    koef = (double)(m - 1) / (double)(n - 1);
    
    for(int y = 0; y < m - 1; y++)
    {
        for(int x = 0; x < n - 1 ; x++)
        {
            if(Cover(x, x + 1, y, y + 1))
            {
                cout << '#';
                result++;
            }
            else
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    
    cout << result;
    
    return 0;
}

bool Cover(int minX, int maxX, int minY, int maxY)
{
    double funcIn = (minX) * koef;
    double funcOut = (maxX) * koef;
    if(funcIn == maxY || funcOut == minY)
        return false;
    return (funcIn >= minY && funcIn <= maxY) || (funcOut >= minY && funcOut <= maxY ) ||
    (funcIn <= minY && funcOut >= maxY);
}

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
int koef_dot_n;

double koef;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    int result = 0;
    cin >> n >> m;
    
    if (m > n)
        std::swap(m,n);
    
    koef = (double)m / n;
    int offsetY = 1;
    
    for(int x = 1; x < n; x++)
    {
        if(x * koef < (double)offsetY)
        {
            result++;
        }
        else if (x * koef == offsetY)
        {
            offsetY += 1;
            result++;
        }
        else
        {
            offsetY += 1;
            result += 2;
        }
    }
    
    
    
    for(int y = 0; y < m - 1; y++)
    {
        for(int x = 0; x < n - 1 ; x++)
        {
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    
    cout << result;
    
    return 0;
}


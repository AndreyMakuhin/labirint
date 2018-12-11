//
//  main.cpp
//  kvartals
//
//  Created by Андрей Макухин on 07.12.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
	int result = 0;
	
	int n, m;
    
    cin >> n >> m;
    
    if (m > n)
        std::swap(m,n);	
	    
    int offsetY = 0;
    
    for(int x = 0; x < n - 1 ; x++)
    {
        if((m - 1) * x / (double)(n - 1) == offsetY)
        {
            result += 1;
			offsetY++;			
        }        
        else if ((m - 1)  * x / (double)(n - 1) > offsetY)
        {
            offsetY += 1;
            result += 2;			
        }
		else if ((m - 1) * x / (double)(n - 1) < offsetY)
		{			
			result++;			
		}
    }

    cout << result;
    
    return 0;
}


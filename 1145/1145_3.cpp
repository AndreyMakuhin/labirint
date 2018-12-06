//
//  main.cpp
//  rope
//
//  Created by Андрей Макухин on 01.12.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//
#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct cell
{
    int x;
    int y;
    bool operator ==(cell other)
    {
        return this->x == other.x && this->y == other.y;
    }
};

int n, m;
int max_lenght = 0;

vector<char> labirint;
vector<bool> msk;
vector<bool> msk_find;

int GetLenghtRope(cell next, int len);
cell FindStart(cell next);

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cin >> n;
    cin >> m;
    
    char input;
    while(cin >> input)
    {
        labirint.push_back(input);
        msk.push_back(false);
        msk_find.push_back(false);
    }
    
    cell start{1,1};
    bool isStart = false;
    for(int i = 1; i < m - 1; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            
            start = {j, i};
            if(labirint[i * n + j] == '.')
            {
                isStart = true;
                break;
            }
        }
        if(isStart)
            break;
    }
    
    int result = GetLenghtRope(start, 0);
    
    cout << max_lenght;
    
    return 0;
}

int GetLenghtRope(cell next, int lenght)
{
    if(labirint[next.y * n + next.x] == '#' || msk[next.y * n + next.x] == true)
        return 0;
    
    msk[next.y * n + next.x] = true;
    
    cell dir[] = {  {next.x + 1, next.y},
                    {next.x - 1, next.y},
                    {next.x, next.y - 1},
                    {next.x, next.y + 1}
                };
    
    int right = GetLenghtRope(dir[0], lenght+1);
    int left = GetLenghtRope(dir[1], lenght+1);
    int up = GetLenghtRope(dir[2], lenght+1);
    int down = GetLenghtRope(dir[3], lenght+1);
    
    int lenghts[4] = { right, left, up, down};
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 - i; j++ )
        {
            if(lenghts[j] < lenghts[j+1])
            {
                int temp = lenghts[j];
                lenghts[j] = lenghts[j+1];
                lenghts[j+1] = temp;
            }
        }
    }
    
    if(lenghts[0] == 0)
    {
        return lenght;
    }
    
    int new_max = lenghts[0] + lenghts[1] - 2 * lenght;
    
    if(new_max > max_lenght)
    {
        max_lenght = new_max;
    }
    
    return lenghts[0];
}

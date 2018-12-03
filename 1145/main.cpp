//
//  main.cpp
//  rope
//
//  Created by Андрей Макухин on 01.12.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct cell
{
    int x;
    int y;
};

int n, m;

vector<char> labirint;
vector<bool> msk;

int GetLenghtRope(cell next, int len);

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
    }
    
    cell start{0,0};
    bool isStart = false;
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
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
    
    cout << result;
    
    return 0;
}

int GetLenghtRope(cell next, int lenght)
{
    if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
        return 0;
    
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
    
    if(right > lenght) right -= lenght;
    if(left > lenght) left -= lenght;
    if(up > lenght) up -= lenght;
    if(down > lenght) down -= lenght;
    
    int lenghts[5] = { lenght, right, left, up, down};
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++ )
        {
            if(lenghts[j] < lenghts[j+1])
            {
                int temp = lenghts[j];
                lenghts[j] = lenghts[j+1];
                lenghts[j+1] = temp;
            }
        }
    }
    
    return lenghts[0] + lenghts[1];
    
}

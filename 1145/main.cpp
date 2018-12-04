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
    bool operator ==(cell other)
    {
        return this->x == other.x && this->y == other.y;
    }
};

int n, m;
cell GSTART{0,0};
bool startFounded = false;

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
    
    cell pre_start{0,0};
    bool isStart = false;
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            
            pre_start = {j, i};
            if(labirint[i * n + j] == '.')
            {
                isStart = true;
                break;
            }
        }
        if(isStart)
            break;
    }
    
    cell dummy = FindStart(pre_start);
    //cout << pre_start.x << " " << pre_start.y << endl;
    //cout << GSTART.x << " " << GSTART.y << endl;
    
    
    int result = GetLenghtRope(GSTART, 0);
    
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
    
    if(right > 0) right -= lenght;
    if(left > 0) left -= lenght;
    if(up > 0) up -= lenght;
    if(down > 0) down -= lenght;
    
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

cell FindStart(cell next)
{
    cell dir[] = {  {next.x + 1, next.y},
        {next.x - 1, next.y},
        {next.x, next.y - 1},
        {next.x, next.y + 1}
    };
    
    if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
        return next;
    
    if(labirint[next.y * n + next.x] == '#' || msk_find[next.y * n + next.x] == true)
        return next;
    
    msk_find[next.y * n + next.x] = true;
    
    if ((labirint[dir[0].y*n + dir[0].x] == '#' || msk_find[dir[0].y * n + dir[0].x] == true) &&
        (labirint[dir[1].y*n + dir[1].x] == '#' || msk_find[dir[1].y * n + dir[1].x] == true) &&
        (labirint[dir[2].y*n + dir[2].x] == '#' || msk_find[dir[2].y * n + dir[2].x] == true) &&
        (labirint[dir[3].y*n + dir[3].x] == '#' || msk_find[dir[3].y * n + dir[3].x] == true) &&
        !startFounded)
    {
        GSTART = next;
        startFounded = true;
    }
    
    cell right = FindStart(dir[0]);
    cell left = FindStart(dir[1]);
    cell up = FindStart(dir[2]);
    cell down = FindStart(dir[3]);
    
    /*if (right == next && left == next && up == next && down == next && !startFounded)
    {
        GSTART = next;
        startFounded = true;
    }*/
    return {-1, -1};
    
}

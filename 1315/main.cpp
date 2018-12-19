//
//  main.cpp
//  speleolog
//
//  Created by Андрей Макухин on 19.12.2018.
//  Copyright © 2018 Андрей Макухин. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cell
{
    int x;
    int y;
};


int width;
int height;
int dist;
bool hasEscape = false;

cell upexit{-1, -1};

vector<char> map;
queue<cell> myQ;

void FindExit(cell start);
void Flood();
void Escape(cell start);
void CleanMap();

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    
    int x;
    int y;
    
    cin >> width >> height >> x >> y >> dist;
    
    char inp;
    for(int i = 0; i < width * height; i++)
    {
        cin >> inp;
        map.push_back(inp);
    }
    
    FindExit({x,y});
    Flood();
    Escape({x,y});
    
    map[(height - y) * width + x - 1] = 'i';
    map[(height - upexit.y) * width + upexit.x - 1] = 'v';
    
    
    ///////дебажный вывод
            printf("%d %d %d %d %d\n", width, height, x, y, dist);
    
            for(int i = 0; i < width*height; i++)
            {
                cout << map[i];
                if((i + 1) % width == 0)
                {
                    cout << "\n";
                }
            }
            cout << "\n";
    
    ////////////
    
    if(hasEscape)
        cout << "Can be rescued by himself\n";
    else
        cout << "Rescue operation required\n";
    
    return 0;
}

void FindExit(cell start)
{
    if(start.y > height )
    {
        upexit = {start.x, start.y - 1};
    }
    
    if(map[(height - start.y) * width + start.x - 1] == '.' )
    {
        map[(height - start.y) * width + start.x - 1] = '-';
        FindExit({start.x + 1, start.y});
        FindExit({start.x - 1, start.y});
        FindExit({start.x, start.y + 1});
        FindExit({start.x, start.y - 1});
    }
}

void Flood()
{
    myQ.push(upexit);
    
    while(!myQ.empty())
    {
        cell recent = myQ.front();
        if(map[(height - recent.y) * width + recent.x - 1] == '-' ||
           map[(height - recent.y) * width + recent.x - 1] == 'v' ||
           map[(height - recent.y) * width + recent.x - 1] == 'i' ||
           map[(height - recent.y) * width + recent.x - 1] == '.')
        {
            map[(height - recent.y) * width + recent.x - 1] = 'o';
            
            myQ.push({recent.x, recent.y - 1});
            myQ.push({recent.x - 1, recent.y});
            myQ.push({recent.x + 1, recent.y});
        }
        
        myQ.pop();
    }
}

void Escape(cell start)
{
    if(!hasEscape)
    {
        int  d = dist;
        myQ.push(start);
        
        while(!myQ.empty())
        {
            cell recent = myQ.front();
            if(recent.y > height)
            {
                hasEscape = true;
                break;
            }
            if((map[(height - recent.y) * width + recent.x - 1] == '-' ||
               map[(height - recent.y) * width + recent.x - 1] == '.') && !hasEscape)
            {
                map[(height - recent.y) * width + recent.x - 1] = 'x';
                CleanMap();
                Escape(recent);
            }
            if((map[(height - recent.y) * width + recent.x - 1] == 'o' ||
                map[(height - recent.y) * width + recent.x - 1] == 'x') && d > 0
               && !hasEscape)
            {
                map[(height - recent.y) * width + recent.x - 1] = 'z';
                d--;
                myQ.push({recent.x, recent.y - 1});
                myQ.push({recent.x, recent.y + 1});
                myQ.push({recent.x + 1, recent.y});
                myQ.push({recent.x - 1, recent.y});
            }
            myQ.pop();
        }
    }
    
    CleanMap();
    
}

void CleanMap()
{
    for(int i = 0; i < width*height; i++)
    {
        if(map[i] == 'z')
           {
               map[i] = 'o';
           }
    }
    while(!myQ.empty())
    {
        myQ.pop();
    }
}
